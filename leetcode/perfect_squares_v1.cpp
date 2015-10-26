#include<iostream>
#include<cmath>
#include<string>

using namespace std;

class Solution{
    public:
        int numSquares(int n){
            int num = 0;
            if(n > 0){
                int tmp = (int)sqrt(n);
                num=1 + numSquares(n - tmp*tmp);
            }
            return num;
        }
};


int main()
{

    Solution s;
    cout << s.numSquares(1) << endl;
    cout << s.numSquares(3) << endl;
    cout << s.numSquares(13) << endl;
    cout << s.numSquares(113) << endl;
    cout << s.numSquares(1113) << endl;
    cout << s.numSquares(1111111113) << endl;
    
    return 0;
}
