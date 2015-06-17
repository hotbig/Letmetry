#include<iostream>
#include<vector>
#include<map>

using namespace std;

class Solution{
    public:
        int majorityElement(vector<int>& nums){
            map<int, int> mymap;

            for(int i = 0; i < nums.size(); i++)
            {
                if( mymap.find(nums[i]) == mymap.end())
                {
                    mymap[nums[i]] = 1;
                }
                else
                {
                    mymap[nums[i]] += 1;
                    if(mymap[nums[i]] > nums.size()/2)
                        return nums[i];
                }
            }

            return 0;
        }
};


int main()
{
    Solution s;
    
    return 0;
}
