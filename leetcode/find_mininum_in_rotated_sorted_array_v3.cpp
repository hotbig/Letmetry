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
            if(nums[end] > nums[start]) 
                return nums[start];

            while(start<end)
            {
                int mid = start+(end-start)>>1;
                if(nums[mid] > nums[start])
                    start=mid + 1;
                
                if(nums[mid] < nums[end])
                    end = mid;
                else
                    start = end;
            }
            return nums[end];
        }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(3);
    cout << s.findMin(v);

    v.push_back(1);
    cout << s.findMin(v);
    
    v.push_back(2);
    cout << s.findMin(v);
    return 0;
}
