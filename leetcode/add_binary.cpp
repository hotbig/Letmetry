#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:
        string addBinary(string a, string b){
            string ret = "";
            int carry = 0;
            int i = a.size() - 1, j = b.size() - 1;

            for(; i>=0 && j>=0; i--, j--)
            {
                if(a[i] == '0' && b[j] == '0'){
                    ret.insert(0, 1, '0'+carry);
                    carry = 0;
                }
                else if(a[i] == '1' && b[j] == '1'){
                    ret.insert(0, 1, '0'+carry);
                    carry = 1;
                }
                else{
                    if(carry == 1){
                        ret.insert(0, 1, '0');
                        carry = 1;
                    }
                    else{
                        ret.insert(0, 1, '1');
                    }
                }
            }

            if(i < 0)
            {
                for(;j >= 0; j--)
                {
                    if(b[j] == '0')
                    {
                        ret.insert(0, 1, '0'+carry);
                        carry = 0;
                    }
                    else
                    {
                        if(carry == 1){
                            ret.insert(0, 1, '0');
                            carry = 1;
                        }
                        else{
                            ret.insert(0, 1, '1');
                        }
                    }
                }
            }
            else if(j < 0)
            {
                for(;i >= 0; i--)
                {
                    if(a[i] == '0')
                    {
                        ret.insert(0, 1, '0'+carry);
                        carry = 0;
                    }
                    else
                    {
                        if(carry == 1){
                            ret.insert(0, 1, '0');
                            carry = 1;
                        }
                        else{
                            ret.insert(0, 1, '1');
                        }
                    }
                }
            }

            if(carry != 0)
                ret.insert(0, 1, '1');

            return ret;   
        }
};


int main()
{
    Solution s;
    cout << s.addBinary("1", "") << endl;
    cout << s.addBinary("1", "1") << endl;
    cout << s.addBinary("1", "111") << endl;
    cout << s.addBinary("100", "111") << endl;
    
    return 0;
}
