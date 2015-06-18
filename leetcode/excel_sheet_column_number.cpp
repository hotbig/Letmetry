#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:
        int titleToNumber(string s){
            int ret = 0;
            while(!s.empty())
            {
                char c = *(s.begin());
                if(c >= 'A' && c <= 'Z')
                {
                    ret = ret*26 + (1+(c-'A'));
                }
                else
                {
                    return -1;
                }
                s.erase(s.begin());
            }
            return ret;
        }
};


int main()
{
    Solution s;

    cout << s.titleToNumber("A") << endl;
    cout << s.titleToNumber("AB") << endl;
    
    return 0;
}
