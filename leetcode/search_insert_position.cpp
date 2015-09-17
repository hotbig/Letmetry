#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        int searchInsert(vector<int>& nums, int target){
            int i = 0;
            for(; i < nums.size(); i++)
            { 
                if(nums[i] >= target) return i;
            } 
            return i;
        }
        int searchInsert_Improved(vector<int>& nums, int target){
            int start=0;
            int end=nums.size();
            while(start<end)
            {
                int mid = start+(end-start)/2;
                if(nums[mid] > target)
                {
                    if(mid-1 >= 0)
                    {
                        if(nums[mid-1] < target)
                            return mid;
                        else if(nums[mid-1]==target)
                            return mid-1;
                        else
                            end=mid-1;
                    }
                    else
                    {
                        return 0;
                    }
                }
                else if(nums[mid] < target)
                {
                    if(mid+1 < nums.size())
                    {
                        if(nums[mid+1] >= target)
                            return mid+1;
                        else
                            start=mid+1;
                    }
                    else
                    {
                        return mid+1; 
                    }
                }
                else
                    return mid;
            }
            return 0;
        }
};


int main()
{
    Solution s;
    
    return 0;
}
