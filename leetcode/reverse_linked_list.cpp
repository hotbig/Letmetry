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
        ListNode* reverseList(ListNode* head){
            struct ListNode* curr = head;
            struct ListNode* prev = NULL;
            struct ListNode* next = NULL;

            while(curr != NULL )
            {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            head = prev;
            return head;
        }
};

int main(void)
{
    int i;
    struct ListNode* head = new ListNode(0);
    struct ListNode* curr = head;

    for(i = 0; i < 0; i++)
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
    head = s.reverseList(head);

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
