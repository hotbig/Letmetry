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


void printTree(TreeNode* root)
{
    if(root != NULL)
    {
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
        delete root;
    }
}

void printVectorTree(vector<TreeNode*> v)
{
    for(vector<TreeNode*>::iterator it=v.begin(); it != v.end(); it++)
    {
        printTree(*it);
        cout << endl;
    }
}

TreeNode* copyOfTree(TreeNode* root)
{
    if(root != NULL)
    {
        TreeNode* new_root = new TreeNode(root->val);
        new_root->left = copyOfTree(root->left);
        new_root->right = copyOfTree(root->right);
    }
    else
    {
        return NULL;
    }
}

class Solution{
    public:
        vector<TreeNode*> helper(int start, int end)
        {
            vector<TreeNode*> v;
            if(start > end)
            {
                  v.push_back(NULL);// quite important to add this for NO child
            }
            else if(end - start == 0)
            {
                v.push_back(new TreeNode(start));
            }
            else if(end - start == 1)
            {
                TreeNode* root = new TreeNode(start);
                root->right = new TreeNode(end);
                v.push_back(root);

                root = new TreeNode(end);
                root->left = new TreeNode(start);
                v.push_back(root);
            }
            else
            {
                for(int i = start; i <= end; i++)
                {
                    vector<TreeNode*> v_l = helper(start,  i-1);
                    vector<TreeNode*> v_r = helper(i+1,    end);

                    for(vector<TreeNode*>::iterator it = v_l.begin(); it != v_l.end(); it++)
                    {
                        for(vector<TreeNode*>::iterator rt = v_r.begin(); rt != v_r.end(); rt++)
                        {
                            TreeNode* root = new TreeNode(i);
                            root->left = *it;
                            root->right = *rt;
                            v.push_back(root);
                        }
                    }
                }
            }

            return v;
        }

        vector<TreeNode*> generateTrees(int n){
            return helper(1, n);
        }


};


int main()
{
    Solution s;
    printVectorTree(s.generateTrees(4));
    return 0;
}
