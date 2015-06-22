#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
            int i = 0, j = 0;
            if(nums1.size() == (m+n))
                nums1.erase(nums1.begin()+m, nums1.begin()+n+m);

            while(j < n){
                if(i == nums1.size()){
                    nums1.insert(nums1.end(), nums2.begin()+j, nums2.end()); 
                    break;
                }

                if(i < nums1.size() && nums2[j] <= nums1[i]){
                    nums1.insert(nums1.begin()+i, nums2[j]);
                    j++;
                }
                i++;
            }
        }
};

void printV(vector<int>& v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{
    Solution s;
    vector<int> v1, v2;
    v1.push_back(1);
    v1.push_back(0);
    v2.push_back(2);
    s.merge(v1, 1, v2, v2.size());
    printV(v1);

    
    return 0;
}
