#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution{
    public:
        string simplifyPath(string path){
            stack<string> stk;
            string word;

            for(int i = 0; i < path.size(); i++)
            {
                if(path[i] == '.')
                {
                    i++;
                    if(path[i] == '/') continue;
                    else if(path[i] == '.')
                    {
                        if(!stk.empty())
                        {
                            stk.pop();
                        }
                        continue;
                    }
                }
                else if(path[i] == '/')
                {
                    if(!word.empty())
                    {
                        stk.push(word);
                        word.clear();
                    }
                }
                else
                {
                    word+=path[i];
            //        word.clear();
                }
            }
            if(!word.empty()) stk.push(word);
            

            string ret;
            ret.insert(0, 1, '/');

            while(stk.size()>1)
            {
                ret.insert(1, stk.top());
                ret.insert(1, 1, '/');
                stk.pop();
            }
            if(stk.size() == 1)
            {
                ret.insert(1, stk.top());
                stk.pop();
            }
            return ret;
        }
};


int main()
{
    Solution s;
    cout << s.simplifyPath("/a/./b/..////../c/") << endl;;
    
    return 0;
}
