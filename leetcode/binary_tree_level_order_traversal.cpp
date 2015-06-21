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

class Solution{
        vector<vector<int> >res;
    public:
        void DFS(TreeNode* root, int level)
        {
            if(root == NULL) return;
            if(level == res.size())
            {
                res.push_back(vector<int>());
            }
            res[level].push_back(root->val);
            DFS(root->left, level+1);
            DFS(root->right, level+1);
        }
        vector<vector<int> > levelOrderBottom(TreeNode* root)
        {
            DFS(root, 0);
            return vector<vector<int> >(res.begin(), res.end());
        }
};


int main()
{
    Solution s;
    TreeNode a(0);
    TreeNode b(-3);
    TreeNode c(-9);
    TreeNode d(-8);
    TreeNode e(2);
    TreeNode f(-5);
    TreeNode g(5);
    TreeNode h(-2);
#if 0
       1
     2   5
   3  4 6  7
#endif 
    a.left = &b;
//    a.right = &h;
//    b.left = &c;
//    b.right = &d;
//    c.left = &e;
//    e.left = &g;
//    d.right=&f;


    
    printVV(s.levelOrderBottom(&a));

    return 0;
}
