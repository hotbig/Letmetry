#include<iostream>
#include<string>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{
    public:
        TreeNode* invertTree(TreeNode* root)
        {
            if(root != NULL)
            {
                TreeNode* tmp = root->left;
                root->left = invertTree(root->right);
                root->right = invertTree(tmp);
            }
            return root;
        }
};


int main()
{
    Solution s;
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(1);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    TreeNode g(7);
    TreeNode h(8);


    return 0;
}
