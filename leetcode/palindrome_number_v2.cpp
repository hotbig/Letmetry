#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:
        bool isPalindrome(int x){
           // 111, 1, 121, -1, 12321 123321 22
            int a = 0;
            if(x < 0) return false;

            while(x>a)
            {
                a = a*10 + (x%10);
                x = x/10;
            }
            
            return (x == a || (a/10)==x);
        }
};


int main()
{
    Solution s;
    cout << (s.isPalindrome(111) ? "yes":"no") << endl;
    cout << (s.isPalindrome(1) ? "yes":"no") << endl;
    cout << (s.isPalindrome(121) ? "yes":"no") << endl;
    cout << (s.isPalindrome(-1) ? "yes":"no") << endl;
    cout << (s.isPalindrome(12321) ? "yes":"no") << endl;
    cout << (s.isPalindrome(123321) ? "yes":"no") << endl;
    cout << (s.isPalindrome(22) ? "yes":"no") << endl;
    
    return 0;
}
