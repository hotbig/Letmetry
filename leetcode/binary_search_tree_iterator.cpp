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

void printTree(TreeNode* root)
{
    if(root != NULL)
    {
        cout << root->val << endl;
        printTree(root->left);
        printTree(root->right);
        delete root;
    }
}

class BSTIterator{
    vector<TreeNode*> stack;
    int nextVal;
    public:
        BSTIterator(TreeNode* root){
            updateStack(root);
        }

        void updateStack(TreeNode* root)
        {
            while(root!=NULL)
            {
                stack.push_back(root);
                root = root->left;
            }
        }

        bool hasNext(){
            if(stack.size() > 0)
            {
                TreeNode* tmp = *(stack.end()-1);
                stack.erase(stack.end()-1);
                nextVal = tmp->val;
                updateStack(tmp->right);
                
                return true;
            }
            else
            {
                return false;
            }
        }

        int next(){
            return nextVal;
        }
};

int main()
{
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(6);
    root->right = new TreeNode(9);

    BSTIterator i = BSTIterator(root);
    while(i.hasNext()) cout << i.next () << endl;




    return 0;
}
