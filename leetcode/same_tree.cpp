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
};


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

    cout << (s.isSameTree(&a, &a) ? "same" : "not same") <<endl;;
    
    a.left = &b;
    cout << (s.isSameTree(&a, &c) ? "same" : "not same") <<endl;;
    
    c.left = &b;
    cout << (s.isSameTree(&a, &c) ? "same" : "not same") <<endl;;
    
    c.right = &d;
    cout << (s.isSameTree(&a, &c) ? "same" : "not same") <<endl;;
    return 0;
}
