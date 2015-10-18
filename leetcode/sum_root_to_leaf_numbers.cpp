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


class Solution{
    int sum ;
    public:
        void dfs(TreeNode* root, int path)
        {
            if(root != NULL)
            {
                path = path*10 + (root->val);
                if(root->right == NULL && root->left == NULL)
                {
                    sum += path;
                    return;
                }
                dfs(root->right, path);
                dfs(root->left, path);
            }
        }

        int sumNumbers(TreeNode* root)
        {
            sum = 0;
            dfs(root, 0);
            return sum;
        }
};

int main()
{
    Solution s;
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(3);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    TreeNode g(7);
    TreeNode h(8);

    a.left = &b;
    a.right = &e;
    e.left = &f;
    e.right = &g;
    cout << s.sumNumbers(&a) << endl;
    return 0;
}
