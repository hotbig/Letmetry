#include<iostream>
#include<string>

#include<vector>
using namespace std;

class Solution{
    public:
        // 123   
        int numDecodings(string s)
        {
            int total = 0;
            int size = s.size();
            if(size >= 1) total = 1;
            vector<int> v(size, 1);

            for(int i = 0; i < size; i++)
            {
                if(((i+1)<size) && ( s[i] == '1' || (s[i] == '2' && s[i] <= '6')))
                {
                    v[i] = 2;
                }
                else if(s[i] <= '0')
                {
                    v[i] = 0;
                }
            }

            for(int i = 0; i < size; i++)
            {
                total *= v[i];
            }

            return total;
        }
        
        int numDecodings1(string s){
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

    cout << s.numDecodings("121999999999999999999999999999999999999991999991") << endl;
    
    return 0;
}
