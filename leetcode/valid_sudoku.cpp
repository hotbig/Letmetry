#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>

using namespace std;

class Solution{
    public:
        bool isValidSudoku(vector<vector<char> > & board){
            map<int, set<char> > m1;
            map<int, set<char> > m2;
            map<int, set<char> > m3; // square
            vector<int> v1(9,0);
            vector<int> v2(9,0);
            vector<int> v3(9,0);

            for(int i = 0; i < board.size(); i++){
                for(int j = 0; j < board[i].size(); j++){
                    if(board[i][j] != '.'){
                        if(board[i][j] < '0' || board[i][j] >'9'){
                            return false;
                        }
                        int k = i/3+(j/3)*3;
                        m1[i].insert(board[i][j]);
                        m2[j].insert(board[i][j]);
                        m3[k].insert(board[i][j]);
                        v1[i] += 1;
                        v2[j] += 1;
                        v3[k] += 1;
                    }
                }
            }

            for(int i = 0; i < v1.size(); i++){
                if(m1[i].size() != v1[i])
                    return false;
            }
            for(int i = 0; i < v2.size(); i++){
                if(m2[i].size() != v2[i])
                    return false;
            }
            for(int i = 0; i < v3.size(); i++){
                if(m3[i].size() != v3[i])
                    return false;
            }
            return true;
        }
};


int main()
{
    Solution s;
    char a1[] = {'5','3','.','.','7','.','.','.','.'};
    char a2[] = {'6','.','.','1','9','5','.','.','.'};
    char a3[] = {'.','9','8','.','.','.','.','6','.'};
    char a4[] = {'8','.','.','.','6','.','.','.','3'};
    char a5[] = {'4','.','.','8','.','3','.','.','1'};
    char a6[] = {'7','.','.','.','2','.','.','.','6'};
    char a7[] = {'.','6','.','.','.','.','2','8','.'};
    char a8[] = {'.','.','.','4','1','9','.','.','5'};
    char a9[] = {'.','.','.','.','8','.','.','7','9'};

    vector<char> v1(a1, a1+sizeof(a1)/sizeof(char));
    vector<char> v2(a2, a2+sizeof(a2)/sizeof(char));
    vector<char> v3(a3, a3+sizeof(a3)/sizeof(char));
    vector<char> v4(a4, a4+sizeof(a4)/sizeof(char));
    vector<char> v5(a5, a5+sizeof(a5)/sizeof(char));
    vector<char> v6(a6, a6+sizeof(a6)/sizeof(char));
    vector<char> v7(a7, a7+sizeof(a7)/sizeof(char));
    vector<char> v8(a8, a8+sizeof(a8)/sizeof(char));
    vector<char> v9(a9, a9+sizeof(a9)/sizeof(char));

    vector<vector<char> > board;
    board.push_back(v1);
    board.push_back(v2);
    board.push_back(v3);
    board.push_back(v4);
    board.push_back(v5);
    board.push_back(v6);
    board.push_back(v7);
    board.push_back(v8);
    board.push_back(v9);
    
    cout << (s.isValidSudoku(board)?"Valid":"Invalid") << endl;

    board[1][0] = '8';
    cout << (s.isValidSudoku(board)?"Valid":"Invalid") << endl;

    for(int i=0; i < board.size(); i++)
    {
        board[i].assign(9, '.');
    }
    cout << (s.isValidSudoku(board)?"Valid":"Invalid") << endl;

    board[1][0] = '9';
    board[2][0] = '9';
    cout << (s.isValidSudoku(board)?"Valid":"Invalid") << endl;

    board[2][0] = 'A';
    cout << (s.isValidSudoku(board)?"Valid":"Invalid") << endl;
    return 0;
}
