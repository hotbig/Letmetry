#include<iostream>
#include<vector>
#include<cstdlib>

using namespace std;

class Solution{
    public:
        int evalRPN(vector<string>& tokens){
			vector<int>  s1;
			int results;
			for(int i=0; i < tokens.size(); i++)
			{
				char to = tokens[i][0];
				if((to >= '0' && to <= '9')||(to=='-' && tokens[i].size()>1))
					s1.push_back(atoi(tokens[i].c_str()));
				else
				{
					int top0 = s1[s1.size()-1];
					int top1 = s1[s1.size()-2];
					switch(to){
						case '+':
							results=top0+top1;
							break;
						case '-':
							results=top1-top0;
							break;
						case '*':
							results=top1*top0;
							break;
						case '/':
							results=top1/top0;
							break;
						default:
							return results;
					}
					s1.erase(s1.end()-2, s1.end());
					s1.push_back(results);
				}
			}
			
			return s1[0];
        }
};


int main()
{
    Solution s;
	vector<string> tokens;
	tokens.push_back("5");
	tokens.push_back("-1");
	tokens.push_back("+");
	cout << s.evalRPN(tokens) << endl;
    
    return 0;
}
