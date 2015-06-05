#include<iostream>
#include<string>
#include<functional>

using namespace std;

class Solution{
    public:
        bool isHappy(int n){
            if(n == 1)
                return true;
            else
            {
                int t = 0;

                while(n > 0)
                {
                    int a = n % 10;
//                  cout << a << "^2 " << "+ ";
                    t = t + a*a;
                    n = n / 10;
                }
//              cout << n << "^2 = " << t << endl;
                return isHappy(t);
            }
        }

        bool isHappy2(int n)
        {
            int t = n;
            int count = 0;

            while(t != 1)
            {
                n = t;
                t = 0;
                while(n > 0)
                {
                    int a = n % 10;
                    t += (a * a);
                    n = n / 10;
                }
                cout << t << endl;

                if(count++ > 550)
                    return false;
            }
            return true;
        }
};

int main(void)
{
    Solution s;
    int input;
    cin >> input;
    cout << (s.isHappy2(input) == true? "is happy": "not happy")  << endl;

    return 0;
}
