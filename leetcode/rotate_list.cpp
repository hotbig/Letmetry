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
        ListNode* rotateRight(ListNode* head, int k){
			if(head == NULL || k == 0) return head;

			ListNode* current = head;
			int node_count = 0;
			for(; current != NULL; current=current->next, node_count++);

			int round = (k % node_count);

			if(round != 0)
			{
				ListNode* pre = head;
				ListNode* next = head->next;
				round = node_count - round;
				round = round - 1;
				while(round && next != NULL)
				{
					pre = next;
					next = next->next;
					round--;
				}

				pre->next = NULL;
				ListNode* tmpHead = head;
				head = next;

				while(next->next != NULL) 
					next = next->next;

				next->next = tmpHead;
			}

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
	head = s.rotateRight(head, 0);
	curr = head;
#if 1
    while(curr != NULL)
    {
        cout << curr->val << " ";
        curr=curr->next;
    }
	cout << endl;
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
