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
        bool hasPathSum(TreeNode* root, int sum)
        {
            if(root == NULL)
                return false;

            if(root->val == sum &&(root->left == NULL && root->right == NULL))
                return true;
            else 
            {
                int leftSum = sum - root->val;
                return hasPathSum(root->left, leftSum)|hasPathSum(root->right, leftSum);
            }
        }
};


int main()
{
    Solution s;
    TreeNode a(5);
    TreeNode b(4);
    TreeNode c(11);
    TreeNode d(7);
    TreeNode e(2);
    TreeNode f(8);
    TreeNode g(13);
    TreeNode h(4);
    TreeNode i(1);
    TreeNode j(-99);

    a.left  = &b;
    b.left  = &c;
    c.left  = &d;
    c.right = &e;
    a.right = &f;
    f.left  = &g;
    f.right = &h;
    h.right = &i;
    h.left = &j;


    cout << (s.hasPathSum(&a, 22) ? "has" : "not has") <<endl;;
    cout << (s.hasPathSum(&a, 27) ? "has" : "not has") <<endl;;
    cout << (s.hasPathSum(&a, 18) ? "has" : "not has") <<endl;;
    cout << (s.hasPathSum(&a, 26) ? "has" : "not has") <<endl;;
    
    cout << (s.hasPathSum(&a, 28) ? "has" : "not has") <<endl;;
    cout << (s.hasPathSum(&i,1 ) ? "has" : "not has") <<endl;;
    cout << (s.hasPathSum(&h,-95 ) ? "has" : "not has") <<endl;;
    return 0;
}
