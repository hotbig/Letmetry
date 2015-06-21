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
        TreeNode* invertTree(TreeNode* root)
        {
            if(root != NULL)
            {
                TreeNode* tmp = root->left;
                root->left = invertTree(root->right);
                root->right = invertTree(tmp);
            }
            return root;
        }
        
        bool isSameTree(TreeNode* p, TreeNode* q)
        {
            if((p != NULL) &&(q != NULL) && (p->val == q->val))
            {
                return (isSameTree(p->left, q->left))&(isSameTree(p->right, q->right));
            }
            else if((p == NULL) && (q == NULL))
            {
                return true;
            }
        
            return false;
        }

        bool isSymmetric(TreeNode* root){
            if(root != NULL)
            {
                TreeNode* left = invertTree(root->left);
                return isSameTree(root->right, left);
            }
            else
            {
                return true;
            }
        }
};


int main()
{
    Solution s;
    TreeNode a(1);
    TreeNode b(2);
    TreeNode c(2);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    TreeNode g(7);
    TreeNode h(8);

    cout << (s.isSymmetric(&a) ? "same" : "not same") <<endl;;

    a.left = &b;
    a.right = &c;

    cout << (s.isSymmetric(&a) ? "same" : "not same") <<endl;;
    
    b.left = &d;
    c.right = &e;
    cout << (s.isSymmetric(&a) ? "same" : "not same") <<endl;;
    
    return 0;
}
