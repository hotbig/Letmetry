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
        TreeNode* groot= NULL;

        TreeNode* buildTree(vector<int>& v1, vector<int>& v2)
        {
            TreeNode* root = NULL;
            int i = 0;
            if(v1.size() == 0 || v2.size() == 0) return root;
            if(v1.size() == 1 && v2.size() == 1) return (new TreeNode(v1[0]));

            root = new TreeNode(v2[v2.size()-1]);
            for(; i < v1.size(); i++){
                if(v1[i] == root->val) break;
            }

            if(i == 0)
            {
                //vector<int> v1_r(v1.begin()+i+1, v1.end());
                //vector<int> v2_r(v2.begin()+i, v2.end()-1);
                v1.erase(v1.begin());
                v2.erase(v2.end()-1);
                root->right = buildTree(v1, v2); 
            }else if(i == (v1.size()-1))
            {
                //vector<int> v1_l(v1.begin(), v1.begin()+i);
                //vector<int> v2_l(v2.begin(), v2.begin()+i);
                v1.erase(v1.end()-1);
                v2.erase(v2.end()-1);
                root->left = buildTree(v1, v2);
            }
            else
            {
//                vector<int> v1_l(v1.begin(), v1.begin()+i);
                vector<int> v1_r(v1.begin()+i+1, v1.end());
//                vector<int> v2_l(v2.begin(), v2.begin()+i);
                vector<int> v2_r(v2.begin()+i, v2.end()-1);
                v1.erase(v1.begin()+i, v1.end());
                v2.erase(v2.begin()+i, v2.end());

                root->left = buildTree(v1, v2);
                root->right = buildTree(v1_r, v2_r);
            }
            return root;
        }
};
void printTree(TreeNode* root)
{
    if(root != NULL)
    {
        printTree(root->left);
        cout << root->val << " ";
        printTree(root->right);
        delete root;
    }
}

int main()
{
    Solution s;
    TreeNode* root;
#if 0
          1
        /  \
       2    5
      / \    \
     3   4    6

#endif
    int a1[] = {3, 2, 4, 1, 5, 6};
    int a2[] = {3, 4, 2, 6, 5, 1};
    vector<int> v1(a1, a1+sizeof(a1)/sizeof(int));
    vector<int> v2(a2, a2+sizeof(a2)/sizeof(int));

    printTree(s.buildTree(v1, v2));
    cout << endl;
#if 0
          1
        2
      3
    4
  5  6
#endif 
//=====================================================================
    int a3[] = {5, 4, 6, 3, 2, 1};
    int a4[] = {5, 6, 4, 3, 2, 1};
    vector<int> v3(a3, a3+sizeof(a3)/sizeof(int));
    vector<int> v4(a4, a4+sizeof(a4)/sizeof(int));


    printTree(s.buildTree(v3, v4));
    cout << endl;

#if 0
          1
           2        
            3
             4
              5
               6
#endif 
//=====================================================================
    int a5[] = {1, 2, 3, 4, 5, 6};
    int a6[] = {6, 5, 4, 3, 2, 1};
    vector<int> v5(a5, a5+sizeof(a5)/sizeof(int));
    vector<int> v6(a6, a6+sizeof(a6)/sizeof(int));

    printTree(s.buildTree(v5, v6));
    cout << endl;

#if 0
          1
           2        
            3
             4
              5
            7  6
          8
         9
       10 
         11
          12
#endif 
//=====================================================================
#if 1
    int a7[] = {1, 2, 3, 4, 10, 11, 12, 9, 8, 7, 5, 6};
    int a8[] = {12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    vector<int> v7(a7, a7+sizeof(a7)/sizeof(int));
    vector<int> v8(a8, a8+sizeof(a8)/sizeof(int));

    printTree(s.buildTree(v7, v8));
    cout << endl;
#endif

    return 0;
}
