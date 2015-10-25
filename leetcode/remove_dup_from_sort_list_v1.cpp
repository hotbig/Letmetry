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

ListNode* deleteDuplicates(ListNode* head) {
	ListNode* cur = head;
	ListNode* prev = NULL;

	while(cur != NULL && cur->next != NULL)
	{
	    int val = cur->val;
	    if(cur->next->val==val)
	    {
		while(cur!= NULL && cur->val == val)
		{
		    ListNode* delNode = cur;
		    cur = cur->next;
		    delete delNode;
		}
		
		if(prev == NULL){
		    head = cur;
		}
		else
		{
		    prev->next = cur;
		}                
	    }
	    else
	    {
		prev = cur;
		cur = cur->next;
	    }
	}
}

int main(void)
{
    int i;
    struct ListNode* head = new ListNode(1);
    struct ListNode* curr = head;
            curr->next = new ListNode(1);


    printList(head);
    head = deleteDuplicates(head);
    if(head == NULL) cout << "NULL" << endl;
    
//    printList(head);
#if 0    
    curr = head;
    while(curr != NULL)
    {
        struct ListNode* next = curr->next;
        delete curr;
        curr = next;
    }
#endif
    return 0;
}

