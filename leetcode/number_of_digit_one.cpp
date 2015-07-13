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
                0,
                1,
                20,
                300,
                4000,
                50000,
                600000,
                7000000,
                80000000,
                900000000
            };

            int count = 0;
            for(int i = sizeof(a)/sizeof(int) - 1; (n > 0 && i >= 0); i--)
            {
                if(n > a[i])
                {
                    int tmp = n/a[i];
                    if(tmp == 1)
                    {
                        count += (n-a[i]);
                        count += (b[i]+1);
                        n = n - a[i];
                    }
                    else
                    {
                        count += (a[i]);
                        count += tmp*(i>0?b[i]:0);
                        n -= tmp*a[i];
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
