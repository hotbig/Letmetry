#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:
        // 123   
        
        int numDecodings(string s){
            if(s.size() == 0) return 0;
            else if(s.size() == 1) return 1;
            else if(s.size() == 2) 
            {
                if(s[0] == '1' || (s[0] == '2' && s[1] <= '6')) 
                    return 2;
                else
                    return 1;
            }
            else
            {
                if(s[0] == '1' || (s[0] == '2' && s[1] <= '6')) 
                {
                    int n1 = numDecodings(s.substr(1, s.size()-1));
                    int n2 = 2*numDecodings(s.substr(2, s.size()-2));
                    return n1+n2;
                }
                else
                {
                    int n1 = numDecodings(s.substr(1, s.size()-1));
                    return n1;
                }
            }
        }
};


int main()
{
    Solution s;

    cout << s.numDecodings("1211114516") << endl;
    
    return 0;
}
