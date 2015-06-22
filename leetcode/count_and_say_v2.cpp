#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class Solution{
    public:
        string say(string s)
        {
            string n="";
            for(int i = 0; i < s.size(); i++)
            {
                char count = '1';
                char curr = s[i];
                while((i+1) < s.size() && s[i] == s[i+1])
                {
                    count += 1;
                    i++;
                }
                n.push_back(count);
                n.push_back(curr);
                count = 0;
            }
            return n;
        }

        string countAndSay(int n){
            string s="";

            int tmp = n;
            s.insert(s.begin(), 1, '0'+(tmp%10));
            tmp /= 10;
            while(tmp>0)
            {
                s.insert(s.begin(), 1, '0'+(tmp%10));
                tmp /= 10;
            }
            cout << s << endl;

            for(int i = 0; i < n; i++)
            {
                s=say(s);
            }

            return s;
        }
};


int main()
{
    Solution s;
    cout << s.countAndSay(45) << endl;
    
    return 0;
}
