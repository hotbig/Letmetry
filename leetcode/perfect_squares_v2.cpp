#include<iostream>
#include<cmath>
#include<string>

using namespace std;

class Solution{
    public:
        int numSquares(int n){
            int num = 0;
            int min = num;
            if(n == 1) return 1;
            else if(n == 2) return 2;
            else if(n == 3) return 3;
            else if(n == 4) return 1;
            else if(n > 4)
            {
                int tmp = (int)sqrt(n);//3
                min = (n-tmp)+1;
                
                for(int i = tmp;i>=(int)sqrt(n-tmp*tmp); i--)
                {
                    num=1 + numSquares(n - i*i);
                    if(num < min) {min = num; }
                    if(min == 1) break;
                    num=0;
                }

            }
            return min;
        }
};


int main()
{

    Solution s;
    int i = 48;
    int s1 = (int)sqrt(i);
    int ss= i-(s1*s1);
    cout << s1 << " " << ss << endl;
//    cout << s.numSquares(1) << endl;
//    for(int i=1; i < 10000; i++)
    cout << i << ": " << s.numSquares(i) << endl;
    
    return 0;
}
