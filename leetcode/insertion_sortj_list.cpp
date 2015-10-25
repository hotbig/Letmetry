#include<cstdio>
#include<cstdlib>
#include<iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

void printList(ListNode *head)
{
    while(head!=NULL){
       cout << head->val << " ";
       head = head->next;
} 
    cout << endl;
}

ListNode* insertionSortList(ListNode* head)
{
    if(head != NULL)
    {
        ListNode* cur = head->next;
        ListNode* curPrev = head;

        while(cur != NULL)
        {
            ListNode* tmpPrev = NULL;
            ListNode* tmp = head;
            for(;tmp!=cur&&tmp->val<=cur->val;)
            {
                tmpPrev=tmp;
                tmp=tmp->next;
            }

            if(tmp == cur) // tail
            {
                curPrev=cur;
                cur=cur->next;
            }
            else if(tmp == head) // header
            {
                curPrev->next = cur->next;
                cur->next = head;
                head = cur;
                cur = curPrev->next;
            }
            else if(tmpPrev!= NULL) // middle
            {
                tmpPrev->next = cur;
                curPrev->next = cur->next;
                cur->next = tmp;
                cur = curPrev->next;
            }
        }
    }

    return head;
}


int main(void)
{
    int i;
    struct ListNode* head = new ListNode(1);
    struct ListNode* curr = head;

    for(int i=0; i < 2; i++)
    {
        if((i % 3)==0)
        {
            curr->next = new ListNode(1);
            curr->next->next = new ListNode(2);
            curr->next->next->next = new ListNode(3);
        }
        else if((i%3)==1)
        {
             curr->next = new ListNode(2);
            curr->next->next = new ListNode(3);
            curr->next->next->next = new ListNode(1);
       }
        else if((i%3)==2)
        {
             curr->next = new ListNode(3);
            curr->next->next = new ListNode(1);
            curr->next->next->next = new ListNode(1);
       }
        curr=curr->next->next->next;

    }

    printList(head);
//    head = mergeSort(head);
    head = insertionSortList(head);
    printList(head);
    curr = head;
    while(curr != NULL)
    {
        struct ListNode* next = curr->next;
        delete curr;
        curr = next;
    }
    return 0;
}

