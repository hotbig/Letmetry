#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int value = 0;
        for(int i=s.size()-1; i >=0; i--)
        {
            if(s[i] == 'I')
            {
               value += 1;
            }
            else if(s[i] == 'V')
            {
               value += 5;
               if(((i-1) >= 0) && s[i-1] == 'I')
               {
                  value-=1;
                  i--;
               }
            }
            else if(s[i] == 'X')
            {
               value += 10;
               if(((i-1) >= 0) && s[i-1] == 'I')
               {
                  value-=1;
                  i--;
               }
            }
            else if(s[i] == 'L')
            {
               value += 50;
               if(((i-1) >= 0) && s[i-1] == 'X')
               {
                  value-=10;
                  i--;
               }
            }
            else if(s[i] == 'C')
            {  
               value += 100;
               if(((i-1) >= 0) && s[i-1] =='X')
               {
                  value-=10;
                  i--;
               }
            }
            else if(s[i] == 'D')
            {
               value += 500;
               if(((i-1) >= 0) && s[i-1] =='C')
               {
                  value-=100;
                  i--;
               }
            }
            else if(s[i] == 'M')
            {
               value += 1000;
               if(((i-1) >= 0) && s[i-1] =='C')
               {
                  value-=100;
                  i--;
               }
            }
        }
        return value;
    }
};


int main()
{
    Solution s;
    cout << s.romanToInt("I") << endl;
    cout << s.romanToInt("II") << endl;
    cout << s.romanToInt("III") << endl;
    cout << s.romanToInt("IV") << endl;
    cout << s.romanToInt("V") << endl;
    cout << s.romanToInt("VI") << endl;
    cout << s.romanToInt("VII") << endl;
    cout << s.romanToInt("VIII") << endl;
    cout << s.romanToInt("IX") << endl;
    cout << s.romanToInt("X") << endl;
    cout << s.romanToInt("XI") << endl;
    cout << s.romanToInt("XII") << endl;
    cout << s.romanToInt("XIII") << endl;
    cout << s.romanToInt("XVIII") << endl;
    cout << s.romanToInt("XIX") << endl;
    cout << s.romanToInt("XX") << endl;
    cout << s.romanToInt("XXI") << endl;
    cout << s.romanToInt("XXII") << endl;
    cout << s.romanToInt("XXIX") << endl;
    cout << s.romanToInt("XXX") << endl;
    cout << s.romanToInt("XXIV") << endl;
    cout << s.romanToInt("XXXV") << endl;
    cout << s.romanToInt("XXXIX") << endl;
    cout << s.romanToInt("XL") << endl;
    cout << s.romanToInt("L") << endl;
    cout << s.romanToInt("LI") << endl;
    cout << s.romanToInt("LV") << endl;
    cout << s.romanToInt("LX") << endl;
    cout << s.romanToInt("XCV") << endl;
    cout << s.romanToInt("XCVIII") << endl;
    cout << s.romanToInt("XCIX") << endl;
    cout << s.romanToInt("C") << endl;
    cout << s.romanToInt("CMXCIX") << endl;
    cout << s.romanToInt("MMMCMXCIX") << endl;
    
    return 0;
}
