#include<iostream>
#include<vector>
#include<string>
#include<limits>

using namespace std;

class Solution{
    public:
        int dfs(int m, int n, vector<vector<int> > &hash)
        {
            if(m >= 1 && n >= 1)
            {
                if(hash[m][n] != -1) return hash[m][n];
                else
                {
                    int p1 = dfs(m-1, n, hash);
                    int p2 = dfs(m, n-1, hash);
                    hash[m-1][n] = p1;
                    hash[m][n-1] = p2;

                    return (p1 + p2);
                }
            }
            return 0;
        }
        
        int uniquePaths(int m, int n)
        {
            vector<vector<int> > hash;
            for(int i = 0; i < 100; i++)
            {
                vector<int> v(100, -1);
                hash.push_back(v);
            }

            hash[0][0] = 0;
            hash[1][1] = 1;
            hash[1][2] = 1;
            hash[2][1] = 1;
            hash[2][2] = 2;

            return dfs(m, n, hash);
        }
};


int main()
{
    Solution s;
    
    cout << s.uniquePaths(100,1) << endl;
    cout << s.uniquePaths(8,2) << endl;

    cout << s.uniquePaths(4,4) << endl;

    cout << s.uniquePaths(20,20) << endl;
    return 0;
}
