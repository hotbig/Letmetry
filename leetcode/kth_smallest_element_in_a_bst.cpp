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
        vector<TreeNode*> stack;
    public:
        void update_stack(TreeNode* root)
        {
            while(root != NULL){
                stack.push_back(root);
                root = root->left;
            }
        }

        int kthSmallest(TreeNode* root, int k)
        {
            int value;
            stack.erase(stack.begin(), stack.end());
            update_stack(root);

            while(k >= 1)
            {
                TreeNode* tmp = *(stack.end()-1);
                value = tmp->val;
                stack.erase(stack.end()-1);

                update_stack(tmp->right);
                k--;
            }

            return value;
        }
};


int main()
{
    Solution s;
    TreeNode* root = new TreeNode(9);
    //root->left = new TreeNode(8);
    //root->left->left = new TreeNode(7);
    root->right = new TreeNode(10);

    cout << s.kthSmallest(root, 2) << endl;;

    return 0;
}
