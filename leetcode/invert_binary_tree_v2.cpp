#include<iostream>
#include<string>
#include<stack>

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
                stack<TreeNode*> s;
                s.push(root);

                while(!s.empty())
                {
                    TreeNode* node = s.top();
                    s.pop();

                    TreeNode* tmp = node->left;
                    node->left = node->right;
                    node->right = tmp;

                    if(node->left) s.push(node->left);
                    if(node->right) s.push(node->right);
                }
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
