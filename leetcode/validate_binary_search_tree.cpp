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
    vector<TreeNode*> stack;
public:
    void update_stack(TreeNode* root)
    {
        while(root != NULL)
        {
            stack.push_back(root);
            root = root->left;
        }        
    }
    bool isValidBST(TreeNode* root) {
        int  prev;

        update_stack(root);
        
        if(stack.size() > 0)
        {
            TreeNode* tmp = *(stack.end()-1);
            prev = tmp->val;
            stack.erase(stack.end()-1);
            
            update_stack(tmp->right);
        }
        
        while(stack.size() > 0)
        {
            TreeNode* tmp = *(stack.end()-1);
            if(prev >= tmp->val) return false;
            else
            {
                prev = tmp->val;
                stack.erase(stack.end()-1);
                update_stack(tmp->right);
            }
        }
        
        return true;
    }
};
