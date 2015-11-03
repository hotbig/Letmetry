#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& matrix) {
        int size = matrix.size();
        int max = (1<<size)-1;

        vector<vector<int> > vv;
        vector<int> v;
        
        vv.push_back(v);
        
        for(int i = 1; i <= max; i++)
        {
            vector<int> tmp;
            int cur = i;
            int t = 0;
            while(cur != 0)
            {
                if(cur & 1) {
                    tmp.push_back(matrix[t]);
                }
                t++;
                cur=cur>>1;
            }
            sort(tmp.begin(), tmp.end());
            vv.push_back(tmp);
        }
        return vv;
    }
};

void printVV(vector<vector<int> >& vv)
{
    for(int i = 0; i < vv.size(); i++)
    {
        for(int j = 0; j < vv[i].size(); j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution s;
    vector<vector<int> > vv;
    vector<int> v;
    v.push_back(8);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(6);
    v.push_back(7);
    v.push_back(9);
    v.push_back(17);
    v.push_back(37);

    vv=s.subsets(v);
    printVV(vv);
    
    return 0;
}
