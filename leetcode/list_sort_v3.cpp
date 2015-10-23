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

ListNode* merge(ListNode* a, ListNode* b, ListNode** preA, ListNode** curA, int step)
{
    ListNode* first=NULL;
    ListNode* prev=*preA;
    int counta=0, countb=0;

    if(a != NULL && b!= NULL) 
        first = (a->val<b->val)?a:b;

    while(a!=NULL && b!=NULL && counta < step && countb < step)
    {
        if(a->val >= b->val)
        {
            ListNode* tmp = b->next;
            b->next = a;
            if(prev != NULL){
                prev->next=b;
            }

            prev = b;
            b = tmp;
            
            countb++;
        }
        else
        {
            prev=a;
            a = a->next;
            counta++;
        }
    }

    if(counta == step) 
        prev->next= b;

    while(counta < step && a!=NULL)
    {
        prev=a;
        a=a->next;
        counta++;
    }

    while((countb<step) && b!=NULL)
    {
        prev=b;
        b=b->next;
        countb++;
    }

    prev->next=b;
    (*preA) = prev;
    (*curA) = (*preA)->next;

    return first;
}

ListNode* stepFoward(ListNode* a, int step)
{
   while(step>0 && a!=NULL) {a=a->next;step--;}
   return (step?NULL:a);
}

ListNode* helper(ListNode* head, int step, int count)
{
    ListNode* curA = head;
    head = NULL;
    ListNode* preA = NULL;
    ListNode* curB = stepFoward(curA, step);
    while((curA != NULL) && (curB != NULL))
    {
         ListNode* ret=merge(curA, curB, &preA, &curA, step);
         if(head == NULL) head = ret;
         curB=stepFoward(curA, step);
    }
    return head;
}

#if 1
ListNode* mergeSort(ListNode* head)
{
    int count = 0;
    for(ListNode* cur=head; cur!=NULL; cur=cur->next) 
    {
        count++; 
    }

    for(int step=1; step < count; step *= 2)
    {
        head=helper(head, step, count);
    }

    return head;
}
#endif
int main(void)
{
    int i;
    struct ListNode* head = new ListNode(1);
    struct ListNode* curr = head;

    for(int i=0; i < 100; i++)
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
    head = mergeSort(head);
    
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

