/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int helper(TreeNode* root, int c)
    {
        int total = 0;
        if(root != NULL)
        {
            total = (1<<(c)) + helper(root->left, c+1);
        }
        return total;
    }
    int helper_x(TreeNode* root, int c)
    {
        int total = 0;
        if(root != NULL)
        {
            total = (1<<(c)) + helper_x(root->right, c+1);
        }
        return total;
    }    
    int countNodes_a(TreeNode* root) {
        if(root!= NULL)
        {
            return 1+countNodes(root->left)+countNodes(root->right);
        }
        else
        {
            return 0;
        }
    }    
    
    int countNodes(TreeNode* root) {
        int left= helper(root, 0);
        int right= helper_x(root, 0);
        if(left == right) return left;
        else
        {
            return countNodes_a(root);
        }
    }
};
