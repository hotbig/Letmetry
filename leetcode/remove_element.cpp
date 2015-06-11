#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        int removeElement(vector<int>& nums, int val){
            for(vector<int>::iterator it=nums.begin(); it < nums.end();)
            {
                if(*it == val)
                    nums.erase(it);
                else
                    it++;
            }
            return nums.size();
        }
};


int main()
{
    Solution s;

//    int arr[] = {4,4,4,4};
    vector<int> v(4,100);
    v[2] = 8;
    cout << s.removeElement(v,100) << endl;
    
    return 0;
}
