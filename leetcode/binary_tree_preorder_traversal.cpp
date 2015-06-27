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
    void DFS(TreeNode* root)
    {
        if(root != NULL)
        {
            v.push_back(root->val);
            DFS(root->left);
            DFS(root->right);
        }
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        DFS(root);
        return v;
    }
};
