#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
    public:
        void sortColors(vector<int>& nums) {
            int c0=0, c1=0, c2=0;

            for(int i = 0; i < nums.size(); i++){
                if(nums[i] == 0) c0++;
                if(nums[i] == 1) c1++;
                if(nums[i] == 2) c2++;
            }

            for(int i = 0; i < nums.size(); i++){
                if(i < c0){nums[i] = 0; continue;}
                if(i < c1){nums[i] = 1; continue;}
                if(i < c2){nums[i] = 2; continue;}
            }        
        }
};


int main()
{
    Solution s;
    
    return 0;
}
