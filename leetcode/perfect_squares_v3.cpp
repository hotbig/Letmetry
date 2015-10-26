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
                int xxx = (int)sqrt(n-tmp*tmp);
                
                for(int i = tmp;i>=xxx; i--)
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
    for(int i=1; i < 1280; i++)
    cout << i << ": " << s.numSquares(i) << endl;
    
    return 0;
}
