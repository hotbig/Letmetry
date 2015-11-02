#include<iostream>
#include<string>
#include<vector>
#include<limits>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        for(int i=0; i < grid.size(); i++)
        {
            for(int j=0; j< grid[i].size();j++)
            {
                if((i-1)>=0 && (j-1)>=0)
                {
                    int up=grid[i-1][j];
                    int left=grid[i][j-1];
                    grid[i][j]+=(up>left?left:up);
                }
                else if((i-1)>=0)
                {
                    grid[i][j]+=grid[i-1][j];
                }
                else if((j-1)>=0)
                {
                    grid[i][j]+=grid[i][j-1];
                }
            }
        }
        return grid[grid.size()-1][grid[0].size()-1];
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
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(7);
//    v1.push_back(11);
//    v1.push_back(15);
    vv.push_back(v1);

    vector<int> v2;
    v2.push_back(2);
    v2.push_back(5);
    v2.push_back(8);
//    v2.push_back(12);
//    v2.push_back(19);
    vv.push_back(v2);
    
    vector<int> v3;
    v3.push_back(3);
    v3.push_back(6);
    v3.push_back(9);
//    v3.push_back(16);
//    v3.push_back(22);
    vv.push_back(v3);
#if 0    
    vector<int> v4;
    v4.push_back(10);
    v4.push_back(13);
    v4.push_back(14);
    v4.push_back(17);
    v4.push_back(24);
    vv.push_back(v4);
    
    vector<int> v5;
    v5.push_back(18);
    v5.push_back(21);
    v5.push_back(23);
    v5.push_back(26);
    v5.push_back(30);
    vv.push_back(v5);
#endif
//    printVV(vv);
    cout << (s.minPathSum(vv)) << endl;
//    printVV(vv);
    
    return 0;
}
