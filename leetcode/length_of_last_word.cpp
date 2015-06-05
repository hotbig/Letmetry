#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:
        int lengthOfLastWord(string s){
            int i = 0;
            int len = 0;

            while(s[i] != '\0')
            {
                if(s[i] != ' ')
                {
                    len++;
                }
                else
                {
                    if(s[i+1] == '\0')
                    {
                        break;
                    }
                    else if(s[i+1] != ' ')
                    {
                        len = 0;
                    }
                }
                i++;
            }

            return len;
        }
};


int main()
{
    Solution s;
    cout << s.lengthOfLastWord("hello world") << endl;
    cout << s.lengthOfLastWord(" world") << endl;
    cout << s.lengthOfLastWord(" world ") << endl;
    cout << s.lengthOfLastWord("  world  a      b                  ") << endl;
    
    return 0;
}
