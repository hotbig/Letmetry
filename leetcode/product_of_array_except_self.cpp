#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
    public:
        vector<int> productExceptSelf(vector<int>& nums){
            int size = nums.size();

            vector<int> prod(size, 1);
            vector<int> left(size, 1);
            vector<int> right(size, 1);

            for(int i = 1; i < size; i++)
            {
                left[i] = left[i-1]*nums[i-1];
            }

            for(int i = size-2; i >= 0; i--)
            {
                right[i] = right[i+1]*nums[i+1];
            }

            for(int i = 0; i < size; i++)
            {
                prod[i] = left[i]*right[i];
            }

            return prod;
        }
};


int main()
{
    Solution s;
    
    return 0;
}
