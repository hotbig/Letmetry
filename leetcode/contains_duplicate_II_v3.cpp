#include<iostream>
#include<vector>
#include<string>
#include<map>

using namespace std;

class Solution{
    public:
        bool containsNearByDuplicate(vector<int>& nums, int k){
            if(k <= 0) return false;

            map<int, int> mymap;
            for(int i = 0; i < nums.size(); i++)
            {
                if( mymap.find(nums[i]) == mymap.end())
                {
                    mymap[nums[i]] = i;
                }
                else
                {
                    if((i - mymap[nums[i]]) <= k)
                        return true;
                    else
                        mymap[nums[i]] = i;
                }
            }

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
