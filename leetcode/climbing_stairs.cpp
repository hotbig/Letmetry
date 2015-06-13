#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:
        int c(int n, int m)
        {
            long int f = 1;
            long int h = 1;
            int t = n-m;

            while(n > t)
                f *= (n--);

            while(m > 0)
                h *= (m--);

            return f/h;
        }

        int climbStairs(int n){
            int half = n/2;
            int sum = 0;

            for(int i = 0; i <= half; i++)
                sum += c(n--, i);
            return sum;
        }

        int climbStairs1(int n){
            if(n <= 0)
                return 0;
            if(n == 1)
                return 1;
            if(n == 2)
                return 2;
            else
            {
                return climbStairs1(n-1)+climbStairs1(n-2);
            }
        }

        int climbStairs2(int n){
            int prev1 = 0;
            int prev2 = 0;

            for(int i = 0; i < n; i++)
            {
                if(i == 0)
                {
                    prev1 = 1;
                    prev2 = 0;

                }
                else if(i == 1)
                {
                    prev1 = 1;
                    prev2 = 1;
                }
                else if(i == 2)
                {
                    prev1 = 2;
                    prev2 = 1;
                }
                else
                {
                    int tmp = prev1;
                    prev1 = prev2 + prev1;
                    prev2 = tmp;
                }
            }

            return prev1+prev2;
        }
};


int main()
{
    Solution s;

    cout << s.climbStairs(6) << endl;
    cout << s.climbStairs1(6) << endl;
    cout << s.climbStairs2(2) << endl;
    cout << s.climbStairs2(228) << endl;
    
    return 0;
}
