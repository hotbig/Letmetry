#include<iostream>
#include<cstdlib>
#include<cstdio>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

class Solution{
    public:
        ListNode* deleteDuplicates(ListNode* head){
            struct ListNode* curr = head;
            struct ListNode* next = NULL;
            if(curr != NULL)
            {
                next = curr->next; 
            }

            while(curr != NULL && next != NULL)
            {
                if(curr->val == next->val)
                {
                    curr->next = next->next;
                    delete next;
                    next = curr->next;
                }
                else
                {
                    curr = next;
                    next = curr->next;
                }
            }

            return head;
        }
};

int main(void)
{
    int i;
    struct ListNode* head = new ListNode(0);
    struct ListNode* curr = head;

    for(i = 0; i < 5; i++)
    {
        struct ListNode* next = new ListNode(0);
        if(next == NULL) 
        {
            cout << "allocation faile" << endl;
            exit(-1);
        }
        
        curr->next = next;
        curr = next;    
    }
    curr->next = new ListNode(1);
    curr->next->next = new ListNode(1);
    curr->next->next->next = new ListNode(2);
    curr->next->next->next->next = new ListNode(2);

    Solution s;
    head = s.deleteDuplicates(head);

    curr = head;
    while(curr != NULL)
    {
        cout << curr->val << " ";
        curr=curr->next;
    }

    cout << endl;
    curr = head;
    while(curr != NULL)
    {
        struct ListNode* next = curr->next;
        delete curr;
        curr = next;
    }
    return 0;
}
