#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        bool isNewIsland(int i, int j, int row, int col, vector<vector<char> >& grid)
        {
            if(grid[i][j] == '0') return false;
            else
            {
                bool isNew = true;
                if(grid[i][j] == 'x' )
                {
                    isNew = false;
                }
                
                if((i-1>=0) && (grid[i-1][j] == 'x'))
                {
                    isNew = false;
                }
                else if((j-1>=0) && (grid[i][j-1] == 'x'))
                {
                    isNew = false;
                }
                else if((i+1<row) && (grid[i+1][j] == 'x'))
                {
                    isNew = false;
                }
                else if((j+1<col) && (grid[i][j+1] == 'x'))
                {
                    isNew = false;
                }


                grid[i][j] = 'x';
                if((i-1>=0) && (grid[i-1][j] == '1'))
                {
                    grid[i-1][j] = 'x';
                }
                else if((j-1>=0) && (grid[i][j-1] == '1'))
                {
                    grid[i][j-1] = 'x';
                }
                else if((i+1<row) && (grid[i+1][j] == '1'))
                {
                    grid[i+1][j] = 'x';
                }
                else if((j+1<col) && (grid[i][j+1] == '1'))
                {
                    grid[i][j+1] = 'x';
                }

                return isNew;
            }
        }


        int numOfIslands(vector<vector<char> >& grid){
            int row = grid.size();
            int col = 0;
            int count = 0;
            if(row > 0) col = grid[0].size();

            
            for(int i = 0; i < row; i++)
            {
                for(int j = 0; j < col; j++)
                {
                    if(isNewIsland(i,j,row, col, grid)) count++;
                }
            }
            return count;
            
        }
};


int main()
{
    Solution s;
    vector<char> v(5, '1');
    vector<vector<char> > vv;
    vv.push_back(v);
    vv.push_back(v);
    vv.push_back(v);

    vv[0][1] = '0';
    vv[1][1] = '0';
    vv[1][3] = '0';
    vv[2][3] = '0';

    cout << s.numOfIslands(vv) << endl;



    
    return 0;
}
