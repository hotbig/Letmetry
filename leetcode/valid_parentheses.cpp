#include<iostream>
#include<vector>
#include<string>
#include<stack>

using namespace std;

class Solution{
    public:
        bool isValid(string s){
            stack<char> stk;
            bool valid = true;

            for(int i=0; i < s.size(); i++)
            {
                if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                    stk.push(s[i]);
                else
                { 
                    if(stk.size() == 0)
                    {
                        valid = false;
                        break;
                    }

                    if(s[i] == ')')
                    {
                        if(stk.top() != '(')
                        {
                            valid = false;
                            break;
                        }
                        else
                        {
                            stk.pop();
                        }
                    }
                    else if(s[i] == ']')
                    {
                        if(stk.top() != '[')
                        {
                            valid = false;
                            break;
                        }
                        else
                        {
                            stk.pop();
                        }
                    }
                    else if(s[i] == '}')
                    {
                        if(stk.top() != '{')
                        {
                            valid = false;
                            break;
                        }
                        else
                        {
                            stk.pop();
                        }
                    }
                }
            }

            if(stk.size() != 0)
                valid = false;

            return valid;
        }
};


int main()
{
    Solution s;
    cout<< ((s.isValid(""))?"yes":"no") << endl;
    cout<< ((s.isValid("()"))?"yes":"no") << endl;
    cout<< ((s.isValid("()()((()))"))?"yes":"no") << endl;
    cout<< ((s.isValid("(([]))"))?"yes":"no") << endl;

    cout<< ((s.isValid(")()"))?"yes":"no") << endl;
    cout<< ((s.isValid("(()((())"))?"yes":"no") << endl;
    cout<< ((s.isValid("((]][[[[]))"))?"yes":"no") << endl;
    
    return 0;
}
