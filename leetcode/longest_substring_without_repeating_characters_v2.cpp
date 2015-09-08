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
                    int start = it->second;
               
                    if(len > max){ 
                        max = len; 
                    }
                    
                    len = i - start;
                    cout << len << s[i] <<endl;
                    for(it = m.begin(); it != m.end(); it++)
                    {
                        if(it->second <= start)
                            m.erase(it);
                    }
                    m[s[i]] = i;
                }else{
                    m[s[i]] = i; len++;
                }
            }

            if(len > max) max = len;
            return max;
        }
};


int main()
{
    Solution s;
    cout << s.lengthOfLongestSubstring("gugfkdmanxdgqiolcrzwjkak") << endl;
    
    return 0;
}
