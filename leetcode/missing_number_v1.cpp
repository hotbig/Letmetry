#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        int missingNumber(vector<int>& nums){
            int max = -1;
            int sum = 0;
            int ret = 0;
            
            for(int i = 0; i < nums.size(); i++)
            {
                if(nums[i] > max) max = nums[i];
                sum += nums[i];
            }

            ret = (((max+1)*max)/2 - sum);

            if(ret == 0){
                if(sum != 1 || nums.size() > 1)
                    ret = max+1;
            }
            
            return ret;
        }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(0);
    cout << s.missingNumber(v) << endl;
    
    return 0;
}
