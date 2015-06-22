#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:
        int strStr(string haystack, string needle){
            int sn = needle.size();
            for(int i = 0, j = 0; i < haystack.size(); i++)
            {
                if((j < sn) && (haystack[i] == needle[j]))
                {
                    if(++j == sn) 
                        return (i+1-sn);
                }
                else
                { 
                    j=0;
                }
            }

            return -1;
        }
};


int main()
{
    Solution s;
    cout << s.strStr("abcdefg", "cd") << endl;
    cout << s.strStr("abcdefg", "gf") << endl;
    
    return 0;
}
