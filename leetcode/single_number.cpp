#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
        int singleNumber(vector<int>& nums){
            int ret = 0;
            for(vector<int>::iterator it=nums.begin(); it < nums.end(); it++)
                ret = ret ^ *it;

            return ret;
        }
};


int main()
{
    Solution s;

    vector<int> v(5, 100);
    v[1] = 4;
    v[2] = 4;
    v[3] = 3;

    cout << s.singleNumber(v) << endl;
    
    return 0;
}
