#include <stdlib.h>
#include <linux/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>

//#define CLOCKID CLOCK_REALTIME
#define CLOCKID CLOCK_MONOTONIC
#define SIG SIGRTMIN

#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                       } while (0)

__u64 start, end;
__u64 RDTSC()
{
    __u32 lo, hi;
    __asm__ __volatile__
    (
     "rdtsc":"=a"(lo),"=d"(hi)
    );
    return (__u64)hi<<32|lo;
}

const int NANO_SECONDS_IN_SEC = 1000000000;
struct timespec* diff(struct timespec *ts1, struct timespec *ts2)
{
    static struct timespec ts;
    ts.tv_sec = ts1->tv_sec-ts2->tv_sec;
    ts.tv_nsec = ts1->tv_nsec-ts2->tv_nsec;
    if(ts.tv_nsec < 0){
        ts.tv_sec--;
        ts.tv_nsec += NANO_SECONDS_IN_SEC;
    }
    return &ts;
}

int handler_stopped = 0;

#define MAX_TIMER_COUNT ((500)*(60))
int g_timer_count = 0;

struct timespec ts_start, ts_end;

static void handler(int sig, siginfo_t *si, void *uc)
{
    if(g_timer_count==0){
        clock_gettime(CLOCK_MONOTONIC, &ts_start);
    }
    else if(g_timer_count==MAX_TIMER_COUNT)
    {
        clock_gettime(CLOCK_MONOTONIC, &ts_end);

        handler_stopped = 1;
        signal(sig, SIG_IGN);
    }
    g_timer_count++;
}

int
main(int argc, char *argv[])
{
   timer_t timerid;
   struct sigevent sev;
   struct itimerspec its;
   long long freq_nanosecs;
   sigset_t mask;
   struct sigaction sa;

   unsigned long cpumask=2;
   sched_setaffinity(0,sizeof(cpumask), &cpumask);

   if (argc != 3) {
       fprintf(stderr, "Usage: %s <sleep-secs> <freq-nanosecs>\n",
               argv[0]);
       exit(EXIT_FAILURE);
   }

   /* Establish handler for timer signal */

   printf("Establishing handler for signal %d\n", SIG);
   sa.sa_flags = SA_SIGINFO;
   sa.sa_sigaction = handler;
   sigemptyset(&sa.sa_mask);
   if (sigaction(SIG, &sa, NULL) == -1)
       errExit("sigaction");

   /* Block timer signal temporarily */

   printf("Blocking signal %d\n", SIG);
   sigemptyset(&mask);
   sigaddset(&mask, SIG);
   if (sigprocmask(SIG_SETMASK, &mask, NULL) == -1)
       errExit("sigprocmask");

   /* Create the timer */

   sev.sigev_notify = SIGEV_SIGNAL;
   sev.sigev_signo = SIG;
   sev.sigev_value.sival_ptr = &timerid;
   if (timer_create(CLOCKID, &sev, &timerid) == -1)
       errExit("timer_create");

   printf("timer ID is 0x%lx\n", (long) timerid);

   /* Start the timer */

   freq_nanosecs = atoll(argv[2]);
   its.it_value.tv_sec = freq_nanosecs / 1000000000;
   its.it_value.tv_nsec = freq_nanosecs % 1000000000;
   its.it_interval.tv_sec = its.it_value.tv_sec;
   its.it_interval.tv_nsec = its.it_value.tv_nsec;

   start=RDTSC();
   if (timer_settime(timerid, 0, &its, NULL) == -1)
        errExit("timer_settime");

   /* Unlock the timer signal, so that timer notification
      can be delivered */

   printf("Unblocking signal %d\n", SIG);

#if 1   
   if (sigprocmask(SIG_UNBLOCK, &mask, NULL) == -1)
       errExit("sigprocmask");
#endif 

   while(!handler_stopped)
       sleep(1);

   struct timespec *ts_tmp = diff(&ts_end, &ts_start);
   printf("MONO, %llu  %llu\n", ts_tmp->tv_sec, ts_tmp->tv_nsec);


   exit(EXIT_SUCCESS);
}

