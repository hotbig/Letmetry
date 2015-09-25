#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        vector<int> grayCode(int n){
            vector<int> v;
            if(n > 0)
            {
                for(int i = 0; i < n; i++)
                {
                    v.push_back((1<<i)-1);
                }
                
                int t = 1 << n;
                for(int i = 0; i < n; i++)
                {
                    v.push_back(t-(1<<i));
                }
            }

            return v;
        }
};


void printV(vector<int>& v)
{
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " " ;
    cout << endl;
}

int main()
{
    Solution s;
    vector<int> v=s.grayCode(1);
    printV(v);
    
    return 0;
}
