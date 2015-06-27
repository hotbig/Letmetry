#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
    public:
        bool containsNearByAlmostDuplicate(vector<int>& v, int k, int t){
            bool found = false;
            for(int i = 0; i < v.size(); i++)
            {
                for(int j = i+1; j < v.size() && j <= (i+k); j++)
                {
                    int val = v[j] > v[i] ? (v[j]-v[i]): (v[i]-v[j]);
                    if(val <= t)
                    {
                        found = true;
                        break;
                    }
                }
            }
            return found;
        }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
 //   v.push_back(8);
 //   v.push_back(10);
    cout << (s.containsNearByAlmostDuplicate(v, 2, 1) ? "found": "Not found") << endl;;
    
    return 0;
}
