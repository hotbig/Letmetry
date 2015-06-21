#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        bool containsNearByDuplicate(vector<int>& nums, int k){
            if(k <= 0) return false;

            for(int i = 0; i < nums.size(); i++)
                for(int j=i+1; j <= (i+k) && j < nums.size(); j++)
                   if(nums[i] == nums[j])
                      return true;

            return false; 
        }
};


int main()
{
    Solution s;
    vector<int> v;

    for(int i = 0; i < 100000; i++)
        v.push_back(i);

    cout << (s.containsNearByDuplicate(v, 4000)?"YES":"NO") << endl;
    
    return 0;
}
