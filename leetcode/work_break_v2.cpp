#include<iostream>
#include<unordered_set>
#include<string>
#include<stack>

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
            stack<int> pos;
            int p = 0;

            int n = s.size();
            for(int i = 0; i < n; i++)
            {
                string tmp = s.substr(p, i+1-p);
                unordered_set<string>::iterator got = wordDict.find(tmp);
//                cout << p << endl;
                if(got != wordDict.end())
                {
                    pos.push(p);
                    pos.push(i);
                    p = i + 1;
                }
                else 
                {
                    if( i == n-1 ) // last not found, then backtracking
                    {
                        if(!pos.empty())
                        {
                            i = pos.top(); pos.pop();
                            p = pos.top(); pos.pop();
                        }
                    }
                }
            }
            return (p == n);
        }
};


int main()
{
    Solution s;
    unordered_set<string> myset = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
    cout << s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", myset) << endl;
    
    return 0;
}
