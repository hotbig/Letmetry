#include<iostream>
#include<string>
#include<limits>

using namespace std;

class Solution{
    public:
        int atoi(string s){
            int ret  = 0;
            int i    = 0;
            int sign = 1;
            int max_r = numeric_limits<int>::max()%10;
            int max_d = numeric_limits<int>::max()/10;
            while(s[i] == ' ') i++; // skip while space

            if(s[i] == '\0'){return ret;           }
            if(s[i] == '-') {sign=-1; i++; max_r++;}
            if(s[i] == '+') {i++;                  }

            while(s[i] != '\0' && s[i] >= '0' &&  s[i] <= '9')
            {
                if((ret > max_d)||((ret == max_d)&&(((s[i] - '0')) > max_r)))
                {
                    return (sign*max_d*10 + sign*max_r);
                }
                else
                {
                    ret = ret*10+(s[i]-'0');
                    i++;
                }
            }
               
            return (ret * sign);
        }
};


int main()
{
    Solution s;

    cout << s.atoi("11") << endl;
    cout << s.atoi("") << endl;
    cout << s.atoi("    ") << endl;
    cout << s.atoi("a") << endl;
    cout << s.atoi("-11") << endl;
    cout << s.atoi("+11") << endl;
    cout << s.atoi("  11") << endl;
    cout << s.atoi("a11") << endl;
    cout << s.atoi("1100a ") << endl;
    cout << s.atoi("--11") << endl;
    cout << s.atoi("11000000000") << endl;
    cout << s.atoi("2147483648") << endl;
    cout << s.atoi("2147483647") << endl;
    cout << s.atoi("-2147483648") << endl;
    cout << numeric_limits<int>::max() << endl;
    
    return 0;
}
