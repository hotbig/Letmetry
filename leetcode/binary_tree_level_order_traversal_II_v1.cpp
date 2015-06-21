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
        vector<vector<int> > merge(vector<vector<int> > v1, vector<vector<int> > v2)
        {
            if(v1.size() > v2.size())
            {
                for(int i=v1.size()-v2.size(), j=0; i<v1.size() && j<v2.size(); i++)
                {
                    v1[i].insert(v1[i].end(), v2[j].begin(), v2[j].end());
                }
                return v1;
            }
            else
            {
                for(int i=v2.size()-v1.size(), j=0; i<v2.size() && j<v1.size() ;i++, j++)
                {
                    v2[i].insert(v2[i].begin(), v1[j].begin(), v1[j].end());
                }
                return v2;
            }
            
        }
        vector<vector<int> > levelOrderBottom(TreeNode* root)
        {
            vector<int> v;
            vector<vector<int> > vv, vl, vr;

            if(root != NULL)
            {
                v.push_back(root->val);
                vl = levelOrderBottom(root->left);
                vr = levelOrderBottom(root->right);

                vv = merge(vl, vr);
                vv.push_back(v);
            }
            return vv;
        }
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
    printVV(s.levelOrderBottom(&a));
#if 0
       1
     2   5
   3  4 6  7
#endif 
    a.left = &b;
//    b.left = &c;
//    b.right = &d;
    a.right = &e;
    e.left = &f;
    e.right = &g;
    
    printVV(s.levelOrderBottom(&a));

    return 0;
}
