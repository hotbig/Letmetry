#include<cstdio>
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
        ListNode* hasCycle(ListNode* head){
            ListNode* cur1 = head;
            ListNode* cur2 = NULL;
            int count = 0;
            if(head == NULL) return NULL;
            cur2 = head->next;

            while(cur1 != NULL && cur2 != NULL)
            {
                if(cur1 == cur2)
                {
                    cur2=cur2->next;
                    cur1=head;

                    while(cur1 != cur2)
                    {
                        cur1=cur1->next;
                        cur2=cur2->next;
                    }
                    return cur1;
                }
                else
                {
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                    if(cur2 != NULL) cur2 = cur2->next;
                }
            }

            return NULL;
        }
};

int main(void)
{
    int i;
    struct ListNode* head = new ListNode(0);
    struct ListNode* curr = head;

    for(i = 0; i < 13; i++)
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
    curr->next = head->next->next->next->next;
    ListNode* cycle = s.hasCycle(head);
    cout << cycle->val << endl;
#if 0
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
        if(next==cycle) break;
    }
    return 0;
}
