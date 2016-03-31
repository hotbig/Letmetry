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

		void helper(TreeNode* root, vector<int>& v)
		{
			if(root == NULL) return;

			helper(root->left, v);
			helper(root->right, v);
			v.push_back(root->val);
		}
        vector<int> postorderTraversal(TreeNode* root)
        {
			vector<int> v;
            if(root == NULL) return v;

			helper(root, v);
			return v;
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

    a.left = &b;
    b.left = &c;
    b.right = &d;

    a.right = &e;

    e.left = &f;

    c.right = &g;
    g.right = &h;



    return 0;
}
