#include<iostream>
#include<string>
#include<vector>

using namespace std;

void printV(vector<int>& v)
{
for(int j = 0; j < v.size(); j++)
{
cout << v[j] << " ";
}
cout << endl;
}

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
            for(int j = 0; j < matrix[i].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    m[i] = 0; n[j] = 0;
                }
            }
        }
        for(int i = 0; i < m.size(); i++)
        {
	    if(m[i] == 0) zero_row(matrix, i);
        }        
        for(int i = 0; i < n.size(); i++)
        {
	    if(n[i] == 0) zero_col(matrix, i);
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
    vector<int> v1;
	v1.push_back(0);
	v1.push_back(0);
	v1.push_back(0);
	v1.push_back(5);
    vector<int> v2;
	v2.push_back(4);
	v2.push_back(3);
	v2.push_back(1);
	v2.push_back(4);
    vector<int> v3;
	v3.push_back(0);
	v3.push_back(3);
	v3.push_back(1);
	v3.push_back(4);
    vector<int> v4;
	v4.push_back(1);
	v4.push_back(3);
	v4.push_back(1);
	v4.push_back(4);
    vector<int> v5;
	v5.push_back(0);
	v5.push_back(0);
	v5.push_back(1);
	v5.push_back(4);
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v4);
    vv.push_back(v5);
    printVV(vv);
    s.setZeroes(vv);
    printVV(vv);
    
    return 0;
}
