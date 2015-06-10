#include<iostream>
#include<string>
#include<limits>
using namespace std;

class Solution{
    public:
        int reverse(int x){
            int y = 0;
            
            int min = numeric_limits<int>::min()/10 - 1 ;
            int max = numeric_limits<int>::max()/10 + 1;

            while(x != 0)
            {
                if(y > max || y < min)
                    return 0;

                y = y*10 + x%10;
                x = x/10;
            }
            return y;
        }
};


int main()
{
    Solution s;
    cout <<    s.reverse(123) << endl;
    cout <<    s.reverse(-123) << endl;
    cout <<    s.reverse(-89234234) << endl;

    cout <<    s.reverse(1534236469) << endl;
    
    
    return 0;
}
