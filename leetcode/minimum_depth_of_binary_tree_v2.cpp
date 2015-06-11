#include<iostream>
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
        int minDepth(TreeNode* root)
        {
            int min_left = 0;
            int min_right = 0;
                
            if(root == NULL)
                return 0;

            if(root->left != NULL)
            {
                 min_left=1+minDepth(root->left);
            }

            if(root->right != NULL)
            {
                min_right=1+minDepth(root->left);
            }
                           
            return (min_left<min_right)?min_left:min_right;
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

    cout << s.minDepth(&a) << endl;
    
    a.left = &b;
    cout << s.minDepth(&a) << endl;

    a.right = &c;
    cout << s.minDepth(&a) << endl;

    (a.left)->left = &d;
    cout << s.minDepth(&a) << endl;

    (a.left)->left = &d;
    (a.left)->right = &e;
    cout << s.minDepth(&a) << endl;
    return 0;
}
