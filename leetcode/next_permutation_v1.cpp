#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        void reverse(vector<int>& v)
        {
            vector<int> v_copy;
            int j = v.size()-1;
            for(; j > 0; j--)
            {
                v_copy.push_back(v[j]);
            }
            int i = 1;
            for(vector<int>::iterator it = v_copy.begin(); it !=v_copy.end(); it++)
            {
                v[i++] = *it;
            }
        }
        bool helper(vector<int>& v)
        {
            int i = v.size() - 1;
            while(i > 0){
                if(v[0] < v[i]) break;
                i--;
            }

            if(i <= 0) return false;
            else
            {
                int tmp = v[i];
                v[i] = v[0];
                v[0] = tmp;

                reverse(v);
                return true;
            }
        }

        void nextPermutation(vector<int>& nums){
            for(int i = nums.size() - 2; i >= 0; i--)
            {
                vector<int> tmp;
                tmp.assign(nums.begin()+i, nums.end());
                if(helper(tmp) == true) 
                {
                    for(int j = tmp.size() -1 ; j >= 0; j--)
                    {
                        nums[i+j] = tmp[j];
                    }
                    return;
                }
                else if(i == 0)
                {
                    vector<int> tmp;
                    tmp.assign(nums.rbegin(), nums.rend());
                    nums.assign(tmp.begin(), tmp.end());
                }
            }
        }
};

void printV(vector<int>& v)
{
    int s = v.size();
    for(int i = 0; i < s; i++)
        cout << v[i] << " ";
    cout << endl;
}

int main()
{
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    s.nextPermutation(v);
    printV(v);
    
    return 0;
}
