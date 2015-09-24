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
            int min = nums[0];

            for(int i = 1; i < nums.size(); i++)
            {
                if(nums[i] < min) {
                    min = nums[i];
                    break;
                }
            }
            return min;
        }
};


int main()
{
    Solution s;
    
    return 0;
}
