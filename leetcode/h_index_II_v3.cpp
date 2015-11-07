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
            int low = 0, high=size-1;
            while(low <= high)
            {
                int mid=low+((high-low)>>1);

                if(citations[mid] == (size-mid))
                    return size-mid;
                else if(citations[mid] > (size-mid))
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            
            }

            return size-(high+1);

#if 0
            for(int i = 0; i < size; i++)
            {
                if((size-i) <= citations[i])
                {
                    return (size-i);
                }
            }
#endif
        }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    cout << s.hIndex(v) << endl;

    return 0;
}
