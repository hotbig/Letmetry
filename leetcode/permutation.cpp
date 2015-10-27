#include<iostream>
#include<vector>
#include<string>

using namespace std;
//http://web.cse.ohio-state.edu/~gurari/course/cis680/cis680Ch19.html
class Solution{
    public:
        void helper(vector<int> &nums, int start, vector<vector<int> > &vv)
        {
            if(start == nums.size()-1) 
            {
                vector<int> v(nums.begin(), nums.end());
                vv.push_back(v);
                return;
            }

            for(int i = start; i < nums.size(); i++)
            {
                int a = nums[start];
                nums[start]=nums[i];
                nums[i] = a;
                helper(nums, start+1, vv);
                nums[i]=nums[start];
                nums[start]=a;
            }
        }
        vector<vector<int> >  permute(vector<int>& nums){
            vector<vector<int> > vv;
            helper(nums, 0, vv);
            return vv;
        }
};

void printVV(vector<vector<int> > &vv)
{
    for(int i = 0; i < vv.size(); i++)
    {
        for(int j = 0; j < vv[i].size(); j++)
            cout << vv[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<vector<int> > vv=s.permute(v);
    printVV(vv);
    return 0;
}
