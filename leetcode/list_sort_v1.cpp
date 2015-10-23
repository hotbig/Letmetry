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



ListNode* helper(ListNode* a, ListNode* b, ListNode** preA, ListNode** curA, int step)
{
    ListNode* first=NULL;
    ListNode* end = NULL;
    ListNode* prev=*preA;
/*
8 9 5 7 10 12 3 11 44 88
*/
#if 0
a=8
b=5
preA=NULL
curA=8
step=2

tmp=7
5->next=8
prev=5
b=7
countb=1

5->next=7
prev=7
7->next=8
b=10
countb=2

prev=8
a=9
counta=1

prev=9
a


5 7 8 9 3 10 11 12 44 88
a=5
b=3
prev

#endif
    int counta=0;
    int countb=0;
    if(a != NULL && b!= NULL) first = (a->val<b->val)?a:b;
    while(a!=NULL && b!=NULL && counta < step && countb < step)
    {
        if(a->val > b->val)
        {
            if(prev != NULL)
            {
                ListNode* tmp=b->next;
                (prev)->next=b;
                prev=b;
                b->next=a;
                b=tmp;
            }
            else
            {
                ListNode* tmp=b->next;
                b->next=a;
                prev=b;
                b=tmp;
            }
            
            countb++;
        }
        else
        {
            prev=a;
            a = a->next;
            counta++;
        }
    }

    if(counta == step) prev->next= b;

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

ListNode* merge(ListNode* head, int step, int count)
{
    ListNode* curA = head;
    head = NULL;
    ListNode* preA = NULL;
    ListNode* curB = stepFoward(curA, step);
    //if(curB != NULL)
    //cout << curB->val << endl;
    for(int i = 0; (i < count) && (curA != NULL) && (curB != NULL); i *= step)
    {
         ListNode* ret=helper(curA, curB, &preA, &curA, step);
         if(head == NULL) head = ret;
         curB=stepFoward(curA, step);
         i++;
    }
    return head;
}

ListNode* mergeSort(ListNode* head)
{
    int step = 1;
    ListNode* cur = head;
    ListNode* prev = NULL;
    int count = 0;
    while(cur!=NULL)
    {       
        if(cur->next!=NULL && cur->next->val<cur->val)
        {
            ListNode* next=cur->next->next;
            cur->next->next=cur;
            if(prev != NULL) {prev->next= cur->next; prev=cur;}
            else {prev=cur;}
            cur->next = next;
            count += 2;
            cur = next;
        }
        else if(cur->next!=NULL && cur->next->val>cur->val){
            count +=2;
            prev=cur->next;
            cur=cur->next->next;
        }
        else
        {
            count++;
            break;
        }
    }
//    printList(head);
//    cout << count << endl;
//    step=2;
    for(step=2; step < count;)
    {
        head=merge(head, step, count);
  //      cout << step << " " << count << endl;
        step = step*2;
//        prev=NULL;
//        cur=head;
//        head=helper(head, head->next->next->next->next, &prev, &cur, step);
        
    }
    return head;
}

/*
8 9 5 7 10 12 3 11 88 45

2:8 9 5 7 10 12 3 11 45 88

4:5 7 8 9 3 10 11 12 45 88

8:3 5 7 8 9 10 11 12 45 88

16: 3 5 7 8 9 10 11 12 45 88
*/



int main(void)
{
    int i;
    struct ListNode* head = new ListNode(1);
    struct ListNode* curr = head;

//    curr->next = new ListNode(9);
//    curr->next->next = new ListNode(5);
#if 0
    curr->next->next->next = new ListNode(7);
    curr->next->next->next->next = new ListNode(10);
    curr->next->next->next->next->next = new ListNode(12);
    curr->next->next->next->next->next->next = new ListNode(3);
    curr->next->next->next->next->next->next->next = new ListNode(11);
    curr->next->next->next->next->next->next->next->next = new ListNode(45);
    curr->next->next->next->next->next->next->next->next->next = new ListNode(85);
    curr->next->next->next->next->next->next->next->next->next->next = new ListNode(83);
    curr->next->next->next->next->next->next->next->next->next->next->next = new ListNode(83);
    curr->next->next->next->next->next->next->next->next->next->next->next->next = new ListNode(83);

#endif
    head = mergeSort(head);
    

//    ListNode* prevA = NULL;
//    head =helper(head, curr->next->next, &prevA, &curr, 2);
    printList(head);
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
