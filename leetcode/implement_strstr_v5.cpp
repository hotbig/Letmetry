#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:
        int strStr(string haystack, string needle){
            int sn = needle.size();
            if(sn == 0) return 0;

            for(int i = 0, j = 0; i < haystack.size(); i++)
            {
                if((j < sn) && (haystack[i] == needle[j]))
                {
                    if(++j == sn) 
                    {
                        return (i+1-sn);
                    }
                }
                else
                { 
                    if(j != 0)
                    {
                        i = i - j ; //"mississippi", "issip"
                        j=0;
                    }
                }
            }

            return -1;
        }
};


int main()
{
    Solution s;
    cout << s.strStr("abcdefg", "cd") << endl;
    cout << s.strStr("mississippi", "issi") << endl;
    cout << s.strStr("mississippi", "issip") << endl;
    cout << s.strStr("mississippi", "pi") << endl;
//                      01234567890
    return 0;
}
