#include<iostream>
#include<vector>
#include<string>
#include<limits>
using namespace std;

class Solution{
    public:
        int removeDuplicates(vector<int>& nums){
            int len = nums.size();
            int i = 0;

            while(i < (len - 1))
            {
                if(nums[i] == nums[i+1])
                {
                    nums.erase(nums.begin()+i+1);
                    len--;

                    continue;
                }
                
                i++;
            }

            return len;
        }
};


int main()
{
    Solution s;
    int arr[] = {1,1,1};
    vector<int> v(arr, arr+3);
    cout <<    s.removeDuplicates(v) << endl;
    
    int arr1[] = {1,1,2};
    vector<int> v1(arr1, arr1+3);
    cout <<    s.removeDuplicates(v1) << endl;
    
    return 0;
}
