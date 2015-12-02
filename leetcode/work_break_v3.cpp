#include<iostream>
#include<vector>
#include<unordered_set>
#include<string>
#include<stack>

using namespace std;

class Solution{
    unordered_set<string> mywordDict;
    public:
        bool wordBreak(string s, unordered_set<string>& wordDict){
            stack<int> pos;
            int p = 0;

            vector<int> v;

            int n = s.size();

            v.resize(n, 0);

            for(int i = 0; i < n; i++)
            {
                if(v[i] == 1) continue;
                
                string tmp = s.substr(p, i+1-p);
                unordered_set<string>::iterator got = wordDict.find(tmp);

                if(got != wordDict.end())
                {
                    pos.push(p);
                    pos.push(i);
                    p = i + 1;
                    v[i] = 1; 
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
    cout << s.wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", myset) << endl;
    
    return 0;
}
