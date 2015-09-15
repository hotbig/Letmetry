#include<iostream>
#include<string>

using namespace std;

struct TreeLinkNode{
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
};

class Solution{
    public:
        void dfs_left(TreeLinkNode* root, TreeLinkNode* cur)
        {
            if(root!=NULL && cur != NULL)
            {
                cur->next = root->right;
                dfs_left(cur, cur->left);
                dfs_right(cur, cur->right);
            }
        }

        
        void dfs_right(TreeLinkNode* root, TreeLinkNode* cur)
        {
            if(root!=NULL && cur != NULL)
            {
                if(root->next != NULL)
                    cur->next = root->next->left;
                dfs_left(cur, cur->left);
                dfs_right(cur, cur->right);
            }
        }

        void connect(TreeLinkNode* root)
        {
            if(root != NULL)
            {
                root->next = NULL;
                dfs_left(root, root->left);
                dfs_right(root, root->right);
            }
        }
};


int main()
{
    Solution s;
    return 0;
}
