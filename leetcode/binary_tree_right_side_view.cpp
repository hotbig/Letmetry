#include<iostream>
#include<vector>
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
        void helper(TreeNode* root, vector<int>& v, int depth)
        {
            if(root != NULL)
            {
                if(root->right != NULL)
                {
                    if(v.size() == depth) v.push_back(root->right->val);
                    helper(root->right, v, depth+1);
                }
                
                if(root->left != NULL)
                {
                    if(v.size() == depth) v.push_back(root->left->val);
                    helper(root->left, v, depth+1);
                }
            }
        }
        vector<int> rightSideView(TreeNode* root)
        {
            vector<int> v;
            if(root != NULL)
            {
                v.push_back(root->val);
                helper(root, v, 1);
            }
            return v;
        }
};

void printV(vector<int>& v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

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

    a.right = &b;
    a.left = &c;
    c.left = &d;

    vector<int> v=s.rightSideView(&a);
    printV(v);
    return 0;
}
