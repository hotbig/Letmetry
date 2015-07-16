#include<cstdio>
#include<vector>
#include<cstdlib>
#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

class Solution{
    public:
        void reorderList(ListNode* head){
            ListNode* cur = head;
            vector<ListNode* > stack;
            int size = 0;

            while(cur != NULL)
            {
                stack.push_back(cur);
                cur = cur->next;
            }

            cur = head;
            size = stack.size();

            for(int i = 0; (cur!= NULL) && (i < size/2); i++)
            {
                struct ListNode* tmp = cur->next;
                cur->next = stack.back();
                stack.pop_back();
                cur->next->next = tmp;
                cur = tmp;
            }
            if(cur != NULL)
                cur->next = NULL;
        }
};

int main(void)
{
    int i;
    struct ListNode* head = new ListNode(0);
    struct ListNode* curr = head;

    for(i = 0; i < 6; i++)
    {
        struct ListNode* next = new ListNode(i+1);
        if(next == NULL) 
        {
            cout << "allocation faile" << endl;
            exit(-1);
        }
        
        curr->next = next;
        curr = next;    
    }

    Solution s;
    s.reorderList(head);
#if 1
    curr = head;
    while(curr != NULL)
    {
        cout << curr->val << " ";
        curr=curr->next;
    }
#endif 
    curr = head;
    while(curr != NULL)
    {
        struct ListNode* next = curr->next;
        delete curr;
        curr = next;
    }
    return 0;
}
