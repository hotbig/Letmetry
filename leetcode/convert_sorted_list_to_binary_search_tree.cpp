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

class Solution{
    public:
        TreeNode* sortedArrayToBST(vector<int> &nums)
        {
            TreeNode* root = NULL;
            int size = nums.size();

            if(size == 0){ return root; }
            else{
                root = new TreeNode(nums[size/2]);
                vector<int> left(nums.begin(), nums.begin()+size/2);
                vector<int> right(nums.begin()+size/2+1, nums.end());

                root->left = sortedArrayToBST(left);
                root->right = sortedArrayToBST(right);
            }

            return root;
        }
    
        TreeNode* sortedListToBST(ListNode* head) {
            vector<int> v;
            while(head != NULL)
            {
                v.push_back(head->val);
                head = head->next;
            }
                      
            return sortedArrayToBST(v);
        }

};


int main()
{
    Solution s;
    int arr[] = {1};
    vector<int> v(arr, arr+sizeof(arr)/sizeof(int));
    printTree(s.sortedArrayToBST(v));

    return 0;
}
