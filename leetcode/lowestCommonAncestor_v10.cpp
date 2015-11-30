#include<iostream>
#include<string>
#include<stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

class Solution{
       TreeNode* ann;
    public:

        int helper(TreeNode* root, TreeNode* p, TreeNode* q)
        {
            if(root != NULL)
            {
                if(root == p) 
                {
                    if(q == NULL) return 1;

                    int ret = helper(root->right, NULL, q);
                    if(ret == 2) return 2;
                    if(ret == 1) { ann = p; return 2;}
                    ret = helper(root->left, NULL, q);
                    if(ret == 2) return 2;
                    if(ret == 1) { ann = p; return 2;}
                    
                    return 1;
                }
                else if(root == q)
                {
                    if(p == NULL) return 1;

                    int ret = helper(root->right, p, NULL);
                    if(ret == 2) return 2;
                    if(ret == 1) { ann = q; return 2;}
                    ret = helper(root->left, p, NULL);
                    if(ret == 2) return 2;
                    if(ret == 1) { ann = q; return 2;}
                    
                    return 1;
                }
                else
                {
                    int ret = helper(root->right, p, q);
                    if(ret == 2) {return 2;}
                    if(ret == 1) 
                    {
                        ret = helper(root->left, p, q);
                        if(ret==1)
                            {ann = root; return 2;}
                        else 
                            return 1;
                    }
                    if(ret == 0)
                    {
                        ret = helper(root->left, p, q);
                        return ret;
                    }
                }
            }
            return 0;
        }
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
        {
            ann = NULL;
            int ret = helper(root, p, q);
            if (ret != 2) 
                return root;
            else
                return ann;
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
    a.left=&b;
    
    TreeNode* t=s.lowestCommonAncestor(&a, &a,&b);
    cout << t->val << endl;

    b.left=&c;
    t=s.lowestCommonAncestor(&a, &c,&b);
    cout << t->val << endl;

    c.right=&d;
    b.right=&e;
    t=s.lowestCommonAncestor(&a, &d,&e);
    cout << t->val << endl;
    return 0;
}
