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
        ListNode* swapPairs(ListNode* head){
            ListNode* cur = head;
            if(cur != NULL && cur->next != NULL)
            {
                head = cur->next;
            }


            while(cur != NULL && cur->next != NULL)
            {
                ListNode* tmp = cur->next->next;
                cur->next->next = cur;
                cur->next = tmp;
                cur = tmp;
            }

            return head;
        }
};

int main(void)
{
    int i;
    struct ListNode* head = new ListNode(0);
    struct ListNode* curr = head;

  
    for(i = 0; i < 7; i++)
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

    ListNode* cur = 
        s.swapPairs(head);
    while(cur!= NULL)
    {
        cout << cur->val << endl;
        cur = cur->next;

    }
    
    return 0;
}
