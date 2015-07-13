#include<iostream>
#include<string>
#include<limits>

using namespace std;

class Solution{
    public:
        int countDigitOneTest(int n){
            int count = 0;
            for(int i = 0; i <= n; i++)
            {
                int temp = i;
                while(temp > 0)
                {
                    count += ((temp % 10)==1)?1:0;
                    temp = temp / 10;
                }
            }
            return count;
        }
        int countDigitOne(int n){
            int a[] = {
                1, 
                10, 
                100, 
                1000, 
                10000, 
                100000, 
                1000000, 
                10000000, 
                100000000,
                1000000000,
            };
            int b[] = {
                0,                   // <1
                1,                   // <10
                20,                  // <100
                300,                 // <1000
                4000,                // <10000
                50000,               // <100000
                600000,              // <1000000
                7000000,             // <10000000
                80000000,            // <100000000
                900000000            // <1000000000
            };

            int count = 0;
            for(int i = sizeof(a)/sizeof(int) - 1; (n > 0 && i >= 0); i--)
            {
                if(n > a[i])
                {
                    int tmp = n/a[i];
                    if(tmp == 1)
                    {                      //case: 1xxxxx
                        count += (n-a[i]); // add   xxxxx of 1 for 1xxxxx
                        count += (b[i]+1); // add   b[i] of 1  for 100000
                        n = n - a[i];      // calc 1 in xxxxx next
                    }
                    else
                    {                               //case: 2xxxxx
                        count += (a[i]);            // add  100000 of 1 from 100000~199999
                        count += tmp*(i>0?b[i]:0);  // add  2*50000 of 1 for  2*(0~99999)
                        n -= tmp*a[i];              // calc xxxxx next
                    }
                }
                else if(n == a[i])
                {
                    count += (b[i] + 1);
                    break;
                }
            }
            return count;
        }
};


int main()
{
    Solution s;

    cout << s.countDigitOneTest(11) << endl;
    cout << s.countDigitOneTest(25) << endl;
    cout << s.countDigitOneTest(9885781) << endl;
    cout << s.countDigitOne(11) << endl;
    cout << s.countDigitOne(25) << endl;
    cout << s.countDigitOne(9885781) << endl;
    
    return 0;
}
