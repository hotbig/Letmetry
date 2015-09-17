#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        int maxSubArray(vector<int>& nums){
            int max=0, cur=0;
            int neg = numeric_limits<int>::min();//patch for the case
            for(int i=0; i < nums.size(); i++)
            {
                int num = nums[i];
                if(cur+num > 0)
                {
                    cur += num;
                    if(cur > max) max = cur;
                }
                else
                {
                    cur = 0;
                    if(num > neg) neg = num; // patch
                }
            }
            return ((max>0)?max:neg); //patch
        }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(-2);
    v.push_back(1);
    v.push_back(-3);
    v.push_back(4);
    v.push_back(-1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(-5);
    v.push_back(4);
    cout << s.maxSubArray(v) << endl;
    
    return 0;
}
