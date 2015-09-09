#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

int cmp(int a, int b) {
    return a < b;
}
class Solution{
    public:
        int find(vector<int> &nums, int start, int end, int target)
        {
            int ret = 0;
            int value = target - nums[start];
            while(start <= end)
            {
                int mid = start+(end-start)/2;
                if(value < nums[mid])
                    end = mid - 1;
                else if(value > nums[mid])
                    start = mid + 1;
                else
                    return mid;
            }

            return 0;
        }

        vector<int> twoSum(vector<int>& nums, int target){
            int size = nums.size();
            int start = 0, found = 0;
            vector<int> v;
            vector<int> o = nums;
            
            sort(nums.begin(), nums.end(), cmp);
            for(int i = 0; i < size; i++)
            {
                found = find(nums, i, size, target);
                if(found) {
                    start = i;
                    break;
                }
            }

            for(int i = 0; i < size; i++)
            {
                if(o[i] == nums[start])
                {
                    start = i+1; break;
                }
            }

            for(int i = 0; i < size; i++)
            {
                if(o[i] == nums[found])
                {
                    found = i+1; break;
                }
            }
            
            if(found>start) {
                v.push_back(start);v.push_back(found);
            }
            else              
            {
                v.push_back(found);v.push_back(start);
            }


            return v;
        }
};


int main()
{
    Solution s;

    vector<int> v1;
    v1.push_back(3);
    v1.push_back(2);
    v1.push_back(4);

    vector<int> v = s.twoSum(v1,  6);
    cout<< v[0] << " " << v[1] << endl;
    return 0;
}
