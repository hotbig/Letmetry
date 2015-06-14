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
        ListNode* removeNthFromEnd(ListNode* head, int n){
            ListNode dummy(0);
            ListNode* curr = head;
            ListNode* prevRemv = &dummy; // n always valid
            ListNode* remv = NULL;
            dummy.next = head;
            
            while(curr != NULL && (n--) > 0)
                curr = curr->next;
            
            if(n > 0) return head;

            while(curr != NULL)
            {
                prevRemv = prevRemv->next;
                curr = curr->next;
            }
           
            remv = prevRemv->next;
            if(prevRemv->next != NULL)
            {
                prevRemv->next = prevRemv->next->next;
                delete remv;
            }

            return dummy.next;
        }
};

int main(void)
{
    int i;
    struct ListNode* head = new ListNode(0);
    struct ListNode* curr = head;

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
    head = s.removeNthFromEnd(head, 7);

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
