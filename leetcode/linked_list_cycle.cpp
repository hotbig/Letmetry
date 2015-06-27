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
        bool hasCycle(ListNode* head){
            ListNode* cur1 = head;
            ListNode* cur2 = NULL;
            if(head == NULL) return false;
            cur2 = head->next;

            while(cur1 != NULL && cur2 != NULL)
            {
                if(cur1 == cur2) return true;
                else
                {
                    cur1 = cur1->next;
                    cur2 = cur2->next;
                    if(cur2 != NULL) cur2 = cur2->next;
                }
            }

            return false;
        }
};

int main(void)
{
    int i;
    struct ListNode* head = new ListNode(0);
    struct ListNode* curr = head;

    for(i = 0; i < 1; i++)
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
    curr->next = head;
    cout << (s.hasCycle(head)?"has":"not") << endl;
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
    }
    return 0;
}
