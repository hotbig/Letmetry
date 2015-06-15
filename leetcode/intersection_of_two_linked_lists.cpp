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
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB){
            ListNode* curA = headA;
            ListNode* curB = headB;
            int countA = 0;
            int countB = 0;

            if(curA == NULL || curB == NULL)
                return NULL;

            while(curA != NULL)
            {
                countA++; curA=curA->next;
            }
            while(curB != NULL)
            {
                countB++; curB=curB->next;
            }
            curA = headA; 
            curB = headB;

            if(countA > countB)
            {
                for(int i = 0; i < (countA-countB); i++)
                    curA = curA->next;
            }
            else if(countA < countB)
            {
                for(int i = 0; i < (countB-countA); i++)
                    curB = curB->next;
            }

            while(curA != NULL && curB != NULL)
            {
                if(curA == curB) return curA;
                else 
                {
                    curA=curA->next;
                    curB=curB->next;
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

    for(i = 0; i < 2; i++)
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

    for(i = 0; i < 2; i++)
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
    curr->next = head->next;
    Solution s;
    curr = s.getIntersectionNode(head, head1);
    if(curr == NULL)
        cout << "NULL" << endl;
    else
        cout << curr->val << endl;

    curr = s.getIntersectionNode(head, head);
    if(curr == NULL)
        cout << "NULL" << endl;
    else
        cout << curr->val << endl;

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
