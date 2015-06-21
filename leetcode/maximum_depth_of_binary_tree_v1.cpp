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


class Solution{
    public:
        int maxDepth(TreeNode* root) {
            int depth = 0;
            if(root != NULL)
            {
                int left = 0, right = 0;
                if(root->left != NULL)
                    left =  1+maxDepth(root->left);
                if(root->right != NULL)
                    right = 1+maxDepth(root->right);

                depth = left>right?left:right;
            }
            return depth;
        }
};


int main()
{
    Solution s;
    TreeNode a(0);
    TreeNode b(-3);
    TreeNode c(-9);
    TreeNode d(-8);
    TreeNode e(2);
    TreeNode f(-5);
    TreeNode g(5);
    TreeNode h(-2);
#if 0
       1
     2   5
   3  4 6  7
#endif 
    a.left = &b;
    a.right = &h;
    b.left = &c;
    b.right = &d;
    c.left = &e;
    e.left = &g;
    d.right=&f;


    
    cout<< (s.maxDepth(&a)) << endl;;

    return 0;
}
