#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        vector<int> spiralOrder(vector<vector<int> > &vv){
            vector<int> v;
            int m = vv.size();
            int n = 0;

            if(m > 0) 
                n = vv[0].size();
            else 
                return v;

            for(int i = 0, j = 0; i <= m-i-1 && j <= n-j-1; i++, j++)
            {
                for(int a = j; a <= n-j-1; a++)
                    v.push_back(vv[i][a]);
                for(int b = i+1; b <= m-i-1; b++)
                    v.push_back(vv[b][n-j-1]);

                if(m-i-1 > i)
                {
                    for(int c = n-j-1-1; c > j; c--)
                        v.push_back(vv[m-i-1][c]);
                }
                if(j < n-j-1)
                {
                    for(int d = m-i-1; d > i;d--)
                        v.push_back(vv[d][j]);
                }
            }
            return v;
        }
};

void printV(vector<int> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main()
{
    Solution s;

    vector<vector<int> > vv;
    vector<int> v;
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v1.push_back(4);
    v1.push_back(5);
    v1.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    v2.push_back(9);
    v3.push_back(10);
    v3.push_back(11);
    v3.push_back(12);
    vv.push_back(v);
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);

    vector<int> r = s.spiralOrder(vv);
    printV(r);





    
    return 0;
}
