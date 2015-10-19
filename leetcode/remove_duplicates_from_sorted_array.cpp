#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        int removeDuplicates(vector<int>& nums){
            int prev, prevPrev;
            if(nums.size() <= 2) 
                return nums.size();
            else
            {
                prevPrev = nums[0];
                prev = nums[1];
            }

            for(int i=2; i < nums.size();)
            {
                if(prevPrev == prev && prev == nums[i])
                    nums.erase(nums.begin()+i);
                else
                {
                    prevPrev = prev;
                    prev = nums[i];
                    i++;
                }
            }
            return nums.size();
        }

};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);
    cout << s.removeDuplicates(v) << endl;;
    
    return 0;
}
