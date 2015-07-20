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
    vector<int> v;
public:
    void helper(TreeNode* root)
    {
        if(root != NULL)
        {
            helper(root->left);
            v.push_back(root->val);
            helper(root->right);
        }        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        v.erase(v.begin(), v.end());
        
        helper(root);
        return v;
    }
};
