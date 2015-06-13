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
        ListNode* addTwoNumbers(ListNode* l1, ListNode *l2){
            ListNode* l1Head = l1;
            ListNode* prevl1 = NULL;
            ListNode* prevl2 = NULL;
            int carry = 0;
    
            if(l1 == NULL && l2 != NULL)
                return l2;
            else if(l1 != NULL && l2 == NULL)
                return l1;
            else if(l1 == NULL && l2 == NULL)
                return NULL;
    
            while(l1 != NULL && l2 != NULL)
            {
                l1->val += l2->val + carry;
                if(l1->val >= 10)
                {
                    carry = 1;
                    l1->val %= 10;
                }
                else
                {
                    carry = 0;
                }
    
                prevl1 = l1;
                prevl2 = l2;
                l1 = l1->next;
                l2 = l2->next;
            }
    
            if(l1 == NULL && l2 != NULL)
            {
                l2->val += carry;
                if(prevl1 != NULL)
                {
                    prevl1->next = l2;
                    if(prevl2 != NULL)
                        prevl2->next = NULL;
                }
            }
            else if(l1 != NULL && l2 == NULL)
            {
                l1->val += carry;
            }
            else if(l1 == NULL && l2 == NULL)
            {
                if(carry != 0)
                {
                    ListNode *tail = new ListNode(1);
                    prevl1->next = tail;
                }
            }
            
            return l1Head;
        }
};

int main(void)
{
    int i;
    struct ListNode* head = new ListNode(0);
    struct ListNode* curr = head;
    curr->val = 1;

    for(i = 0; i < 3; i++)
    {
        struct ListNode* next = new ListNode(i+1);
        if(next == NULL) 
        {
            cout << "allocation faile" << endl;
            exit(-1);
        }
        
        curr->next = next;
        curr->val = i;
        curr = next;    
    }

    struct ListNode* head1 = new ListNode(0);
    curr = head1;
    curr->val = 9;

    for(i = 0; i < 5; i++)
    {
        struct ListNode* next = new ListNode(9);
        if(next == NULL) 
        {
            cout << "allocation faile" << endl;
            exit(-1);
        }
        
        curr->next = next;
        curr->val = 9;
        curr = next;    
    }
    curr= head1;
    while(curr != NULL)
    {
        cout << curr->val << " ";
        curr=curr->next;
    }
    cout << endl;
    curr= head;
    while(curr != NULL)
    {
        cout << curr->val << " ";
        curr=curr->next;
    }
    cout << endl;
    
    Solution s;
    curr = s.addTwoNumbers(head, head1);

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
    curr = head1;
    while(curr != NULL)
    {
        struct ListNode* next = curr->next;
        delete curr;
        curr = next;
    }
    return 0;
}
