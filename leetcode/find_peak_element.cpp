#include<cstdio>
#include<vector>
#include<cstdlib>
#include<iostream>

using namespace std;

class Solution{
    int found;
    public:
        void helper(vector<int>& nums, int low, int high)
        {
            if(found == -1)
            {
                if(low == high) 
                {
                    if(low == 0 || low == (nums.size()-1))
                        found = low;
                    return;
                }

                if((high - low) == 1)
                {
                    if(high == (nums.size()-1) && nums[high]>nums[low]) 
                        found=high;
                    else if(low == 0 && nums[low]>nums[high]) 
                        found = low;
                    return;
                }

                int mid = low + ((high-low)>>1);
                if(nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1])
                {
                    found = mid;
                }
                else
                {
                    if(found == -1)
                        helper(nums, low, mid);
                    if(found == -1)
                        helper(nums, mid, high);
                }
            } 
        }

        int findPeakElement(vector<int>& nums){
            found = -1;
            helper(nums, 0, nums.size()-1);
            return found;
        }
};

int main(void)
{

    Solution s;
    vector<int> v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);

    
    cout<<s.findPeakElement(v) << endl;
    return 0;
}
