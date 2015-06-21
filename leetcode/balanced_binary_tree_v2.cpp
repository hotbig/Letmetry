#include<iostream>
#include<string>
#include<csetjmp>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};


class Solution{
        bool balanced = true;
    public:
        int depth(TreeNode* root)
        {
            int d = 0;
            if(root != NULL)
            {
                int left  = 1+depth(root->left);
                int right = 1+depth(root->right);
                int min = 0;
                int max = 0;

                if(left > right)
                {
                    min = right;
                    max = left;
                }
                else
                {
                    min = left;
                    max = right;
                }

                if(max - min >1)
                {
                    balanced = false;
                }

                d = max;
            }

            return d;
        }
        bool isBalanced(TreeNode* root)
        {
            if(root == NULL) return true;
            int left = 1+depth(root->left);
            int right = 1+depth(root->right);

            if(balanced == false)
            {
                return false;
            }
            else
            {
                return (left>right) ? (!((left-right)>1)):(!((right-left)>1));
            }
        }
};


int main()
{
    Solution s;
    TreeNode a(1);
    cout << (s.isBalanced(&a) ? "YES" : "NO") << endl;
    TreeNode b(2);
    TreeNode c(1);
    TreeNode d(4);
    TreeNode e(5);
    TreeNode f(6);
    TreeNode g(7);
    TreeNode h(8);

    a.left = &b;
    b.left = &c;
    b.right = &d;

    a.right = &e;
    cout << (s.isBalanced(&a) ? "YES" : "NO") << endl;

    e.left = &f;
    cout << (s.isBalanced(&a) ? "YES" : "NO") << endl;

    c.right = &g;
    g.right = &h;
    cout << (s.isBalanced(&a) ? "YES" : "NO") << endl;

    return 0;
}
