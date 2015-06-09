#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
    public:
        int rob(vector<int>& nums)
        {
            int size = nums.size();
            if(size == 0)
                return 0;
            else if(size == 1)
                return nums[0];
            else if(size == 2)
                return nums[0]>nums[1] ? nums[0]:nums[1];
            else if(size == 3)
            {
                int a = nums[0]+nums[2];
                int b = nums[1];
                
                return a>b?a:b;
            }
            else
            {
                vector<int> v1(nums.begin()+2, nums.end());
                vector<int> v2(nums.begin()+3, nums.end());
                int a = nums[0] + rob(v1);
                int b = nums[1] + rob(v2);
                
                return a>b?a:b;
            }        
        }
};


int main()
{
    Solution s;

    int arr[] = {155,44,52,58,250,225,109,118,211,73,137,96,137,89,
        174,66,134,26,25,205,239,85,146,73,55,6,122,196,128,50,61,
        230,94,208,46,243,105,81,157,89,205,78,249,203,238,239,217,
        212,241,242,157,79,133,66,36,165};

    vector<int> v3(arr, arr + sizeof(arr)/sizeof(int));
    cout << s.rob(v3) << endl;
    return 0;
}
