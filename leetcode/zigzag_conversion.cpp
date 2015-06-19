#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:
        string convert(string s, int numRows) {
            string ret="";
            int n = numRows;
            if( n == 1 || n > s.size())
                return s;
                
             for(int i = 0; i < n; i++)
             {
                if(i == 0 || i== n-1)
                {
                    int count = 0;
                    int index = i+count*(n-1)*2;
                    while(index < s.size())
                    {
                        ret.push_back(s[index]);
                        count++;
                        index = i+count*(n-1)*2;
                    }
                }
                else
                {
                    int count = 0;
                    int index = i;
                    ret.push_back(s[index]);
                    count++;
            
                    index = index+((count+1)%2)*(i*2)+(count%2)*(n-1-i)*2;
                    while(index < s.size())
                    {
                        ret.push_back(s[index]);
                        count++;        
                        index = index+((count+1)%2)*(i*2)+(count%2)*(n-1-i)*2;
                    }
                }
             }
             return ret;
        }
};


int main()
{
    Solution s;
    cout << s.convert("PAYPALISHIRING", 14) << endl;
    cout << s.convert("PAYPALISHIRING", 1) << endl;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    cout << s.convert("PAYPALISHIRING", 4) << endl;
    cout << s.convert("PAYPALISHIRING", 5) << endl;
    
    return 0;
}
