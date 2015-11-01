#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int count1(vector<vector<int> >& board, int i, int j)
    {
        int count = 0;
        int row = board.size();
        int col = board[0].size();

        if(((i-1)>=0) && ((j-1)>=0) && (board[i-1][j-1] % 2)) count++;
        if((i-1>=0) && (j>=0) && (board[i-1][j] % 2)) count++;
        if((i-1>=0) && (j+1<col) && (board[i-1][j+1] % 2)) count++;
        if((i>=0) && (j-1>=0) && (board[i][j-1]%2)) count++;
        if((i>=0) && (j+1<col) &&( board[i][j+1]%2)) count++;
        if(((i+1)<row) && ((j-1)>=0) && (board[i+1][j-1]%2)) count++;
        if(((i+1)<row) && (j>=0) && (board[i+1][j]%2)) count++;
        if(((i+1)<row) && ((j+1)<col) && (board[i+1][j+1]%2)) count++;

        return count;
    }
    void gameOfLife(vector<vector<int> >& board) {
        for(int i = 0; i < board.size();i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                int count = count1(board,i,j);
                if(board[i][j] == 1){
                    if(count < 2 || count > 3){
                        board[i][j] = 3;
                    }
                }
                else 
                {
                    if(count == 3) board[i][j]=2;
                }
            }
        }

        for(int i=0; i < board.size(); i++)
        {
            for(int j=0; j < board[i].size(); j++)
            {
                if(board[i][j] == 2) board[i][j] = 1;
                if(board[i][j] == 3) board[i][j] = 0;
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
    for(int i=0; i < 3; i++)
    {
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    vv.push_back(v);
    }

    printVV(vv);
    s.gameOfLife(vv);
    printVV(vv);
    
    return 0;
}
