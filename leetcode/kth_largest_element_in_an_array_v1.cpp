#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        void insert(vector<int>& v, int value, int k)
        {
            int size = v.size();

            int j = 0;
            for(; j < size; j++) if(v[j] > value) break;
            
            if(j > 0) v.insert(v.begin()+j, value);
            if(j ==0) v.insert(v.begin(), value);

            if(v.size() > k) v.erase(v.begin());

        }

        int findKthLargest(vector<int>& nums, int k){
            vector<int> v;

            for(int i = 0; i < nums.size(); i++)
            {
                insert(v, nums[i], k);
            }
            return v[0];
        }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    v.push_back(6);
    v.push_back(4);

    cout << s.findKthLargest(v, 1) << endl;
    cout << s.findKthLargest(v, 2) << endl;
    cout << s.findKthLargest(v, 3) << endl;
    cout << s.findKthLargest(v, 4) << endl;
    cout << s.findKthLargest(v, 5) << endl;
    cout << s.findKthLargest(v, 6) << endl;
    
    return 0;
}
