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
        ListNode* mergeTwoLists(ListNode* l1, ListNode *l2){
            ListNode* head = NULL;
            ListNode* curr = NULL;

            if(l1 == NULL)
                return l2;
            if(l2 == NULL)
                return l1;

            if(l1->val < l2->val)
            {
                head = l1;
                l1 = l1->next;
            }
            else
            {
                head = l2;
                l2 = l2->next;
            }

            curr = head;
            while(l1 != NULL && l2 != NULL)
            {

                if(l1->val <= l2->val)
                {
                    curr->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    curr->next = l2;
                    l2 = l2->next;
                }
                curr = curr->next;
            }

            if(l1 != NULL)
                curr->next = l1;
            if(l2 != NULL)
                curr->next = l2;

            return head;
        }
};

int main(void)
{
    int i;
    struct ListNode* head = new ListNode(0);
    struct ListNode* curr = head;

    for(i = 0; i < 9; i++)
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
    struct ListNode* head1 = new ListNode(0);
    curr = head1;

    for(i = 0; i < 5; i++)
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
    head = s.mergeTwoLists(head, head1);

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
