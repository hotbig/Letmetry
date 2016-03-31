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
        vector<int> postorderTraversal(TreeNode* root)
        {
			vector<TreeNode*> stack;
			vector<int> v;
			TreeNode* lastVisited = NULL;
            if(root == NULL) return v;

			while(stack.size()>0 || root != NULL)
			{
				if(root != NULL)
				{
					stack.push_back(root);
					root=root->left;
				}
				else
				{
					TreeNode* peek = stack[stack.size()-1];
					if(peek->right != NULL && peek->right != lastVisited)
					{
						root = peek->right;
					}
					else
					{
						v.push_back(peek->val);
						lastVisited = peek;
						
						stack.erase(stack.end()-1);
					}
				}
			}
			return v;
        }
};

void printV(vector<int> &v)
{
	for(int i=0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}


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

    a.left = &b;
    b.left = &c;
    b.right = &d;
	vector<int> v= s.postorderTraversal(&a);
	printV(v);

    a.right = &e;

    e.left = &f;

    c.right = &g;
    g.right = &h;



    return 0;
}
