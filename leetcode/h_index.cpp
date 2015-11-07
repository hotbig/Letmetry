#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution{
    public:
        int hIndex(vector<int>& citations){
            sort(citations.begin(), citations.end());

            int size = citations.size();
            for(int i = 0; i < size; i++)
            {
                if((size-i) <= citations[i])
                {
                    return (size-i);
                }
            }

            return 0;
        }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(3);
    cout << s.hIndex(v) << endl;

    v.push_back(0);
    cout << s.hIndex(v) << endl;
   
    v.push_back(6);
    cout << s.hIndex(v) << endl;
    
    v.push_back(1);
    cout << s.hIndex(v) << endl;
    
    v.push_back(5);
    cout << s.hIndex(v) << endl;
    return 0;
}
