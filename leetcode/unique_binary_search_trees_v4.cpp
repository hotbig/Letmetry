#include<iostream>
#include<string>
#include<vector>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};


void printVV(vector<vector<int> > vv)
{
    for(int i = 0; i < vv.size(); i++)
    {
        for(int j = 0; j < vv[i].size(); j++)
        {
            cout << vv[i][j] << " ";
        }
        cout<< endl;
    }
}

void printTree(TreeNode* root)
{
    if(root != NULL)
    {
        cout << root->val << endl;
        printTree(root->left);
        printTree(root->right);
        delete root;
    }
}

class Solution{
    vector<int> v;
    public:
        int nums(int n)
        {
            int total = 0;
            if(v[n] != -1)
            {
                return v[n];
            }
            else
            {
                for(int i = 1; i <= n/2; i++)
                {
                    total += nums(i-1)*nums(n-i);
                }
                    
                total = total*2;

                if(n % 2)
                {
                    total += nums(n/2)*nums(n-n/2-1);
                }
            }

            v[n] = total;

            return total;
        }

        int numTrees(int n)
        {
            v.assign(n+1, -1);
            v[0] = 1;
            v[1] = 1;
            v[2] = 2;
            v[3] = 5;

            return nums(n);
        }

};


int main()
{
    Solution s;
    cout << s.numTrees(1) << endl;
    cout << s.numTrees(2) << endl;
    cout << s.numTrees(3) << endl;
    cout << s.numTrees(4) << endl;
    cout << s.numTrees(5) << endl;
    cout << s.numTrees(16) << endl;

    return 0;
}
