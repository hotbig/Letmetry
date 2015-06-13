#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
        void rotate(vector<int>& nums, int k){
            int size = nums.size();
            k = k % size;
            if(k != 0 && k != size){
                nums.insert(nums.begin(), nums.begin()+size-k, nums.end());
                nums.erase(nums.begin()+size-k, nums.end());
            }
        }
};


int main()
{
    Solution s;
    vector<int> v(6, 1);
    v[1] = 2;
    v[2] = 3;
    v[3] = 4;
    v[4] = 5;
    v[5] = 6;

    s.rotate(v, 8);
    cout << v[0] << endl;
    cout << v[1] << endl;
    cout << v[2] << endl;
    cout << v[3] << endl;
    cout << v[4] << endl;
    cout << v[5] << endl;
    
    return 0;
}
