#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    void zero_row(vector<vector<int> >& matrix, int row)
    {
        for(int j = 0; j < matrix[row].size(); j++) matrix[row][j] = 0;
    }
    void zero_col(vector<vector<int> >& matrix, int col)
    {
        for(int j = 0; j < matrix.size(); j++) matrix[j][col] = 0;
    }
    void setZeroes(vector<vector<int> >& matrix) {
        vector<int> m;
        vector<int> n;
        
        if(matrix.size() > 0)
        {
            m.resize(matrix.size(), 1);
            n.resize(matrix[0].size(), 1);
        }
        
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix.size(); j++)
            {
		        if(matrix[i][j] == 0 )
                {
                    if(m[i] != 0)
                    {
                        m[i]=0; zero_row(matrix, i);
                    }
                    
                    if(n[j] != 0)
                    {
                        n[j]=0; zero_col(matrix, j);
                    }
                }
            }
        }
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
    for(int i=0; i < 1; i++)
    {
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    vv.push_back(v);
    }

    printVV(vv);
    s.setZeroes(vv);
    printVV(vv);
    
    return 0;
}
