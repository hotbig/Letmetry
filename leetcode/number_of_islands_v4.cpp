#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        void connect(int i, int j, int row, int col, vector<vector<char> > & grid)
        {
                if(grid[i][j] == '0' ) return;

                if((i-1>=0) && (grid[i-1][j] == '1'))
                {
                    grid[i-1][j] = 'x';
                    connect(i-1, j, row, col, grid);
                }
                if((j-1>=0) && (grid[i][j-1] == '1'))
                {
                    grid[i][j-1] = 'x';
                    connect(i, j-1, row, col, grid);
                }
                if((i+1<row) && (grid[i+1][j] == '1'))
                {
                    grid[i+1][j] = 'x';
                    connect(i+1, j, row, col, grid);
                }
                if((j+1<col) && (grid[i][j+1] == '1'))
                {
                    grid[i][j+1] = 'x';
                    connect(i, j+1, row, col, grid);
                }
        }
        bool isNewIsland(int i, int j, int row, int col, vector<vector<char> >& grid)
        {
            if(grid[i][j] == '0' || grid[i][j] == 'x') return false;
            else
            {
                bool isNew = true;
                
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


                if(grid[i][j] == '1')
                {
                    grid[i][j] = 'x';
                    connect(i, j, row, col, grid);
                }
                return isNew;
            }
        }


        int numIslands(vector<vector<char> >& grid){
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
    vv[1][2] = '0';
    vv[1][3] = '0';
    vv[2][3] = '0';

    cout << s.numIslands(vv) << endl;

   // cout << s.numIslands(vv) << endl;


    
    return 0;
}
