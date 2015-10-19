#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        vector<vector<int> > combine_helper(int start, int n, int k){
            vector<vector<int> > vv;
            if(n < k || (n-start) < k-1) 
            {
                return vv;
            }
            
            if(k == 1){
                for(int i = start; i <= n; i++){
                    vector<int> v;
                    v.push_back(i);
                    vv.push_back(v);
                }
                return vv;
            }

            for(int i = start; i <= n; i++){
                vector<vector<int> > tt = combine_helper(i+1, n, k-1);
                for(int j = 0; j < tt.size(); j++){
                    tt[j].insert(tt[j].begin(), i);
                    vv.push_back(tt[j]);
                }
            }

            return vv;
        }

        vector<vector<int> > combine(int n, int k){
            return combine_helper(1, n, k);
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
    vector<vector<int> > vv = s.combine(30,14);
    printVV(vv);
    
    return 0;
}
