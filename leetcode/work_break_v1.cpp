#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

class Solution{
    unordered_set<string> mywordDict;
    public:
        bool wordBreak(string s, unordered_set<string>& wordDict){
#if 0
            static int z = 0;
            z++;
            cout << z << s << endl;
#endif 
            if(s.empty()) return true;

            int n = s.size();
            for(int i = 0; i < n; i++)
            {
                string tmp = s.substr(0, i+1);
                unordered_set<string>::iterator got = wordDict.find(tmp);
                if(got != wordDict.end())
                {
                    if(wordBreak(s.substr(i+1, n-(i+1)), wordDict))
                    {
//                        cout << tmp << endl;
                        return true;
                    }
                }
            }
            return false; 
        }
};


int main()
{
    Solution s;
    unordered_set<string> myset = {"le", "lee","t", "code", "r"};
    cout << s.wordBreak("leetcoder", myset) << endl;
    
    return 0;
}
