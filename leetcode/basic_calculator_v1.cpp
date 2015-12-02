#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution{
    public:
        int calculate(string s){
            stack<int> op, num;
            int total=0;
            int i = 0;

            while(i < s.size()){
                if(s[i] >= '0' && s[i] <= '9')
                {
                    int val = s[i]-'0';
                    while(++i<s.size() && s[i] >= '0' && s[i] <= '9') val=val*10+(s[i]-'0');
                    if(i<s.size()) i--;

                    if(!op.empty()){
                        int pre = num.top();
                        if(op.top() == '-'){ pre-= val; }
                        else if(op.top() == '+') {pre+= val;}
                        else{cout << "wrong " << endl;return 0;}
                        num.pop();
                        op.pop();
                        num.push(pre); 
                    }
                    else
                    {
                        num.push(val);
                    }
                }
                else if(s[i] == '+' || s[i] == '-')
                {
                    op.push(s[i]);
                }
                else if(s[i] == ')')
                {
                    if(!op.empty()){
                        int p2 = num.top(); num.pop();
                        int p1 = num.top(); num.pop();

                        if(op.top() == '-')     { p1 -= p2; }
                        else if(op.top() == '+'){ p1 += p2; }
                        else{ cout << "wrong " << endl; return 0; }

                        op.pop();
                        num.push(p1);
                    }
                }
                else if(s[i] == '(')
                {
                    while(s[i] == '(' || s[i] == ' ') i++;
                    if(s[i] >= '0' && s[i] <= '9')
                    {

                        int val = s[i]-'0';
                        while(++i<s.size() && s[i] >= '0' && s[i] <= '9') val=val*10+(s[i]-'0');
                        if(i<s.size()) i--;

                            num.push(val);

                    }
                    else
                    {
                        cout << "wrong" << endl;
                    }
                }
                i++;
            }

            if(!num.empty())
            {
                total = num.top(); num.pop();
            }
            return total;
        }


};


int main()
{
    Solution s;
    cout << s.calculate("13-1-1+1") << endl;
    cout << s.calculate("( ( (15 -11-1))+(1+1))") << endl;
    cout << s.calculate("( ( (15)))") << endl;
    cout << s.calculate("(((15)-((((11))))))") << endl;
    cout << s.calculate("(((15)-(1+15)))") << endl;
    cout << s.calculate("(((15)-(1+15)))+(1-89)+2") << endl;
    cout << s.calculate("(1+(4+5+2)-3)+(6+8)") << endl;
    
    return 0;
}
