#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
        int column;
        int row;
    public:
        void findNeiboring(int a, int b, vector<vector<char> > &board){
            if(a < 0 || a >= row || b < 0 || b >= column) return;
            cout << a << " " << b << endl;

            board[a][b] = 'T';

            if(a-1 > 0 && board[a-1][b] == 'O')
                findNeiboring(a-1, b, board);

            if(a+1 < row && (board[a+1][b] == 'O'))
                findNeiboring(a+1, b, board);
                
            if(b-1 > 0 && board[a][b-1] == 'O')
                findNeiboring(a, b-1, board);

            if(b+1 < column && board[a][b+1] == 'O')
                findNeiboring(a, b+1, board);
        }

        void solve(vector<vector<char> > &board){
            row = board.size();
            if(row > 0)
                column = board[0].size();

            if(row == 0 || column == 0) return;
            
            for(int j = 0; j < column; j++)
            {
                if(board[0][j] == 'O')
                {
                    findNeiboring(0, j, board);
                }
            }

            for(int j = 0; j < column; j++)
            {
                if(board[row-1][j] == 'O')
                {
                    findNeiboring(row-1, j, board);
                }
            }

            for(int j = 0; j < row; j++)
            {
                if(board[j][0] == 'O')
                {
                    findNeiboring(j, 0, board);
                }
            }

            for(int j = 0; j < row; j++)
            {
                if(board[j][column-1] == 'O')
                {
                    findNeiboring(j, column-1, board);
                }
            }

            for(int i = 0; i < row; i++)
                for(int j = 0; j < column; j++)
                {
                    if(board[i][j] == 'T')
                        board[i][j] = 'O';
                    else if(board[i][j] == 'O')
                        board[i][j] = 'X';
                }
        }
};


void printVV(vector<vector<char> > &board)
{
    int row = board.size();
    int column = board[0].size();

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < column; j++)
            cout << board[i][j] << ' ';
        cout << endl;
    }
}
int main()
{
    Solution s;
    vector<char> v0;
    v0.push_back('X');
    v0.push_back('O');
    v0.push_back('X');
    v0.push_back('O');
    v0.push_back('X');
    v0.push_back('O');
    
    vector<char> v1;
    v1.push_back('O');
    v1.push_back('X');
    v1.push_back('O');
    v1.push_back('X');
    v1.push_back('O');
    v1.push_back('X');
 
    vector<char> v2;
    v2.push_back('X');
    v2.push_back('O');
    v2.push_back('X');
    v2.push_back('O');
    v2.push_back('X');
    v2.push_back('O');
    
    vector<char> v3;
    v3.push_back('O');
    v3.push_back('X');
    v3.push_back('O');
    v3.push_back('X');
    v3.push_back('O');
    v3.push_back('X');

    vector<vector<char> > board;
    board.push_back(v0);
    board.push_back(v1);
    board.push_back(v2);
    board.push_back(v3);

    s.solve(board);
    printVV(board);

   return 0;
}
