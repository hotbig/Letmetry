#include <stdlib.h>
#include <string.h>
#include <linux/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>

/*----------------------------------------------------------------*/
#define SECONDS_IN_ONE_MIN 60
#define MS_IN_ONE_SECOND   1000
#define US_IN_ONE_MS       1000
#define NS_IN_ONE_US       1000

#define NS_IN_2MS (2*(US_IN_ONE_MS)*NS_IN_ONE_US)

//#define CLOCKID CLOCK_REALTIME
#define CLOCKID CLOCK_MONOTONIC
#define SIG SIGRTMIN

#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                       } while (0)

typedef enum e_mins
{
    e_mins_1,
    e_mins_2,
    e_mins_4,
    e_mins_8,
    e_mins_16,
    e_mins_end
}e_mins;

static timer_t timerid;

/*----------------------------------------------------------------*/

void delete_timer(void)
{
    if(timer_delete(timerid) != 0){
        printf("timer delete failure \n");
        exit(-1);
    }
}




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
int g_timer_count = 0;
int max_count = 0;

struct timespec ts_start, ts_end;
__u64 tsc_start, tsc_end;

static void handler(int sig, siginfo_t *si, void *uc)
{
    if(g_timer_count==0){
        clock_gettime(CLOCK_MONOTONIC, &ts_start);
        tsc_start=RDTSC();
    }
    else if(g_timer_count==max_count)
    {
        tsc_end=RDTSC();
        clock_gettime(CLOCK_MONOTONIC, &ts_end);

        handler_stopped = 1;
        signal(sig, SIG_IGN);
    }
    g_timer_count++;
}

void start_timer(void)
{
   struct itimerspec its;
   sigset_t mask;
   struct sigaction sa;
#ifdef MY_DEBUG
   printf("Establishing handler for signal %d\n", SIG);
#endif
   sa.sa_flags = SA_SIGINFO;
   sa.sa_sigaction = handler;
   sigemptyset(&sa.sa_mask);
   if (sigaction(SIG, &sa, NULL) == -1)
       errExit("sigaction");

   /* Block timer signal temporarily */

#ifdef MY_DEBUG
   printf("Blocking signal %d\n", SIG);
#endif
   sigemptyset(&mask);
   sigaddset(&mask, SIG);
   if (sigprocmask(SIG_SETMASK, &mask, NULL) == -1)
       errExit("sigprocmask");

   struct sigevent sev;

   /* Create the timer */

   sev.sigev_notify = SIGEV_SIGNAL;
   sev.sigev_signo = SIG;
   sev.sigev_value.sival_ptr = &timerid;
   if (timer_create(CLOCKID, &sev, &timerid) == -1)
       errExit("timer_create");
#ifdef MY_DEBUG
   printf("timer ID is 0x%lx\n", (long) timerid);
#endif
//   freq_nanosecs = atoll(argv[2]);
   its.it_value.tv_sec = NS_IN_2MS / 1000000000;
   its.it_value.tv_nsec = NS_IN_2MS % 1000000000;
   its.it_interval.tv_sec = its.it_value.tv_sec;
   its.it_interval.tv_nsec = its.it_value.tv_nsec;

   if (timer_settime(timerid, 0, &its, NULL) == -1)
        errExit("timer_settime");

   /* Unlock the timer signal, so that timer notification
      can be delivered */
#ifdef MY_DEBUG
   printf("Unblocking signal %d\n", SIG);
#endif

#if 1   
   if (sigprocmask(SIG_UNBLOCK, &mask, NULL) == -1)
       errExit("sigprocmask");
#endif 
}

void init_test(int min, int period)
{
    
    memset((void*)&ts_start, 0, sizeof(struct timespec));
    memset((void*)&ts_end, 0, sizeof(struct timespec));
    max_count = (min*SECONDS_IN_ONE_MIN*MS_IN_ONE_SECOND)/period;
#ifdef MY_DEBUG
    printf("max count: %d\n", max_count);
#endif
}

void start_test(void)
{
    start_timer();
}

void store_result(void)
{
    struct timespec *ts_tmp = diff(&ts_end, &ts_start);
    printf("MONO, %llu  %llu\n", ts_tmp->tv_sec, ts_tmp->tv_nsec);
    //printf("TSC, %llu \n", tsc_end-tsc_start);
}

void halt_test(void)
{
    while(!handler_stopped)  sleep(1);
}

void done_test(void)
{
    halt_test();

    handler_stopped = 0;
    max_count = 0;
    g_timer_count = 0;
    delete_timer();
    store_result();
}

void startstart(int min, int period)
{
    init_test (min, period);
    start_test();
    done_test();
}

int
main(int argc, char *argv[])
{
    unsigned long cpumask=2;
    sched_setaffinity(0,sizeof(cpumask), &cpumask);
    int i = 0;
    int j = 0;
   // int a[] = {1, 2, 4, 8, 16};
    int a[5][5] = {
        {1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2},
        {4, 4, 4, 4, 4},
        {8, 8, 8, 8, 8},
        {16, 16, 16, 16, 16}
    };
    for(; j < 5;j++)
    {
        for(i=0; i < 5;i++)
        {
            printf("%d min: ", a[j][i]);
            startstart(a[j][i], 2);
        }
    }
 //       startstart(2, 2);
    exit(EXIT_SUCCESS);
}

