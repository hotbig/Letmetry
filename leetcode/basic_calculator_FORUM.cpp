#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack <int> nums, ops;
        int num = 0;
        int rst = 0;
        int sign = 1;
        for (char c : s) { 
            if (isdigit(c)) {
                num = num * 10 + c - '0';
            }
            else {
                rst += sign * num;
                num = 0;
                if (c == '+') sign = 1;
                if (c == '-') sign = -1;
                if (c == '(') {
                    nums.push(rst);
                    ops.push(sign);
                    rst = 0;
                    sign = 1;
                }
                if (c == ')' && ops.size()) {
                    rst = ops.top() * rst + nums.top();
                    ops.pop(); nums.pop();
                }
            }
        }
        rst += sign * num;
        return rst;
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
