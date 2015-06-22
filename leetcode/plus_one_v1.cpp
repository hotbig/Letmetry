#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
    public:
        vector<int> plusOne(vector<int>& digits){
            int carry = 0;
            vector<int> v;
            if(digits.size() == 0)
            {
                v.push_back(1);
                return v;
            }

            for(int i = digits.size()-1; i >= 0; i--)
            {
                digits[i] = digits[i] + carry + 1;
                if(digits[i] >= 10)
                {
                    digits[i] %= 10;
                    carry = 1;
                }
                else
                {
                    carry = 0;
                }
            }

            if(carry == 1)
            {
                digits.insert(digits.begin(), 1);
            }
            
            v.insert(v.begin(), digits.begin(), digits.end());

            return v;
        }
};

void printV(vector<int> v)
{
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    Solution s;
    vector<int> v;

    printV(s.plusOne(v));
    
    return 0;
}
