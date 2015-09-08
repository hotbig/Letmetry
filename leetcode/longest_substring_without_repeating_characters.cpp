#include<iostream>
#include<string>
#include<map>

using namespace std;

class Solution{
    public:
        int lengthOfLongestSubstring(string s){
            map<char, int> m;
            map<char, int>::iterator it;
            int len = 0;
            int max = 0;
            for(int i = 0; i < s.size(); i++)
            {
                it = m.find(s[i]);
                if(it != m.end()){
                    if(len > max){ max = len; }
                    
                    m.clear(); 
                    len = 0;
                }else{
                    m[s[i]] = 1; len++;
                }
            }

            if(len > max) max = len;
            return max;
        }
};


int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("abcabcacbdefd") << endl;
    
    return 0;
}
