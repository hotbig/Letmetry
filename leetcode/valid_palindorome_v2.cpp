#include<iostream>
#include<string>

using namespace std;

#define isAZ(x) (((x)<='Z' && (x)>='A')?true:false)
#define isaz(x) (((x)<='z' && (x)>='a')?true:false)
#define is09(x) (((x)<='9' && (x)>='0')?true:false)
#define isSameChar(x,y) (((x)==(y))||((((x)>(y))?((x)-(y)):((y)-(x)))==0x20))

class Solution{
    public:
        bool isPalindrome(string s){
            bool isPalin = true;
            int start=0;
            int end=s.size()-1;

            while(start < end)
            {
                if(!(isAZ(s[start])) && !(isaz(s[start])) && !(is09(s[start])))
                {
                    start++; continue;
                }

                if(!(isAZ(s[end])) && !(isaz(s[end])) && !(is09(s[end])))
                {
                    end--;   continue;
                }

                if(!(isSameChar(s[start], s[end])))
                {
                    isPalin = false; break;
                }

                start++; end--;
            }
            
            return isPalin;
        }
};


int main()
{
    Solution s;
    
    cout << ((isAZ('Z'))?"yes":"no") << endl;
    cout << ((isAZ('a'))?"yes":"no") << endl;

    cout << (s.isPalindrome("A man, a plan, a canal: Panama")?"yes":"no") << endl;;
    cout << (s.isPalindrome("race a car")?"yes":"no") << endl;
    cout << (s.isPalindrome("")?"yes":"no") << endl;
//    cout << (s.isPalindrome(NULL)?"yes":"no");
    cout << (s.isPalindrome("12a21")?"yes":"no") << endl;
    cout << (s.isPalindrome("1-2a2-------1")?"yes":"no") << endl;
    cout << (s.isPalindrome("1-8-1")?"yes":"no") << endl;
    cout << (s.isPalindrome("1-aa8aa-10")?"yes":"no") << endl;
    
    return 0;
}
