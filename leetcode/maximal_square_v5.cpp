#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
		int maxSquare(vector<vector<char> >& matrix, int i, int j, int row, int col, vector<vector<int> >& vv)
		{
			int max = 1;
			if(vv[i][j] != 0) return vv[i][j];

			if((j+1) < col && (i+1) < row && matrix[i+1][j] == '1' 
				&& matrix[i][j+1] == '1' && matrix[i+1][j+1] == '1')
			{
				int a=maxSquare(matrix, i+1, j, row, col, vv);
				vv[i+1][j] = a;
				if(a == 1) return 2;
				int b=maxSquare(matrix, i, j+1, row, col, vv);
				vv[i][j+1] = b;
				if(b == 1) return 2;

				int c=maxSquare(matrix, i+1, j+1, row, col, vv);
				vv[i+1][j+1] = c;

				int min = a > b ? b : a;
				min = min>c ? c : min;

				max = max + min;
			}
			
			return max;
		}

        int maximalSquare(vector<vector<char> >& matrix){
			int max = 0;
			int row = matrix.size();

			if(row == 0) 
				return 0;

			int col = matrix[0].size();
			vector<vector<int> > vv;

			for(int i=0; i < row; i++)
			{
				vector<int> v;
				for(int j = 0; j < col; j++)
				{
					v.push_back(0);
				}
				vv.push_back(v);
			}

			for(int i = 0; i < row; i++)
			{
				for(int j = 0; j < col; j++)
				{
					if(matrix[i][j] == '1')
					{
						int ret = maxSquare(matrix, i, j, row, col, vv);
//						cout << i << ":" << j << ":" << max << endl;
						vv[i][j] = ret;
						if(ret > max) max = ret;
						if(max >= row || max >= col) 
							return max*max;
					}
				}
			}
			
			return max*max;
        }
};


int main()
{
    Solution s;

	char r0[] = {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'};
	char r1[] = {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'};
	char r2[] = {'1', '1', '0', '1', '1', '0', '1', '1', '1', '0', '1', '1', '0', '1', '0', '1', '1'};
	char r3[] = {'1', '1', '1', '1', '1' , '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'};
	char r4[] = {'1', '1', '1', '1', '1' , '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'};
	char r5[] = {'1', '1', '1', '0', '1' , '1', '1', '0', '1', '1', '1', '0', '1', '1', '1', '1', '1'};
	char r6[] = {'1', '1', '1', '1', '1' , '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'};
	char r7[] = {'1', '1', '0', '1', '1' , '0', '1', '1', '0', '1', '1', '1', '1', '1', '0', '1', '1'};
	char r8[] = {'1', '1', '1', '1', '1' , '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'};
	char r9[] = {'1', '1', '1', '1', '1' , '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'};

	vector<char> vr0(r0, r0+sizeof(r0)/sizeof(char));
	vector<char> vr1(r1, r1+sizeof(r1)/sizeof(char));
	vector<char> vr2(r2, r2+sizeof(r2)/sizeof(char));
	vector<char> vr3(r3, r3+sizeof(r3)/sizeof(char));
	vector<char> vr4(r4, r4+sizeof(r4)/sizeof(char));
	vector<char> vr5(r5, r5+sizeof(r5)/sizeof(char));
	vector<char> vr6(r6, r6+sizeof(r6)/sizeof(char));
	vector<char> vr7(r7, r7+sizeof(r7)/sizeof(char));
	vector<char> vr8(r8, r8+sizeof(r8)/sizeof(char));
	vector<char> vr9(r9, r9+sizeof(r9)/sizeof(char));

	vector<vector<char> > vv;
	vv.push_back(vr0);
	vv.push_back(vr1);
	vv.push_back(vr2);
	vv.push_back(vr3);
	vv.push_back(vr4);
	vv.push_back(vr5);
	vv.push_back(vr6);
	vv.push_back(vr7);
	vv.push_back(vr8);
	vv.push_back(vr9);

	cout << s.maximalSquare(vv) << endl;

    return 0;
}
