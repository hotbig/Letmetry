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


void printVV(vector<vector<int> > vv)
{
    for(int i = 0; i < vv.size(); i++)
    {
        for(int j = 0; j < vv[i].size(); j++)
        {
            cout << vv[i][j] << " ";
        }
        cout<< endl;
    }
}
class Solution{
    public:
        vector<vector<int> > levelOrderBottom(TreeNode* root)
        {
            vector<int> v;
            vector<vector<int> > vv, v1, v2;

            if(root != NULL)
            {
                v.push_back(root->val);
                v1 = levelOrderBottom(root->left);
                v2 = levelOrderBottom(root->right);
                if(v1.size() > v2.size())
                {
                    for(int i=v1.size()-v2.size(), j=0; i<v1.size() && j<v2.size(); i++, j++)
                    {
                        v1[i].insert(v1[i].end(), v2[j].begin(), v2[j].end());
                    }
                    v1.push_back(v);
                    return v1;
                }
                else
                {
                    for(int i=v2.size()-v1.size(), j=0; i<v2.size() && j<v1.size() ;i++, j++)
                    {
                        v2[i].insert(v2[i].begin(), v1[j].begin(), v1[j].end());
                    }
                    v2.push_back(v);
                    return v2;
                }
            }
            return vv;
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


    
    printVV(s.levelOrderBottom(&a));

    return 0;
}
