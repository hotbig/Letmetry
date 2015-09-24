#include<iostream>
#include<vector>
#include<string>

using namespace std;

//0 1 2 3 4 5 6 
//1 2 3 4 5 6 0
//4 5 6 7 0 1 2
//9 8 7 6 5 4 3
class Solution{
    public:
        int findMin(vector<int>& nums){
            int start = 0;
            int end = nums.size()-1;

            while(start<=end)
            {
                int mid = start+((end-start)>>1);

                if(mid == start || mid == end){
                    return (nums[start]>nums[end])?nums[end]:nums[start];
                }
                if(nums[mid]>nums[start] && nums[mid] < nums[end]){
                    return nums[start];
                }
                if(nums[mid]>nums[start] && nums[mid] > nums[end]){
                    start = mid+1; continue;
                }
                if(nums[mid]<nums[start] && nums[mid] < nums[end]){
                    end = mid; continue;
                }
            }
        }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(2);
    cout << s.findMin(v) << endl;

    v.push_back(3);
    cout << s.findMin(v) << endl;
    
    v.push_back(1);
    cout << s.findMin(v) << endl;
    return 0;
}
