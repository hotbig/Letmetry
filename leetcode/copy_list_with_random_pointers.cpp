/**
  * Definition for singly-linked list with a random pointer.
  * struct RandomListNode {
  *     int label;
  *     RandomListNode *next, *random;
  *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
  * };
*/
#include<map>
#include<vector>
#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

struct RandomListNode{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x):label(x),next(NULL),random(NULL){}
};

typedef struct RandomListNode RandomListNode;

class Solution {
	public:
	    RandomListNode *copyRandomList(RandomListNode *head) {
		    RandomListNode* copy_head = NULL;
		    if(head != NULL)
		    {
			    RandomListNode* cur = head;
			    RandomListNode* copy_cur = NULL;
			    RandomListNode* copy_pre = NULL;
			    vector<RandomListNode*> v, copy_v;
			    map<RandomListNode*, int> m;
			    int count = 0;

			    while(cur != NULL)
			    {
				    v.push_back(cur->random);
				    m[cur] = count;

				    copy_cur = new RandomListNode(cur->label);
				    copy_v.push_back(copy_cur);
				  
				    if(copy_pre != NULL)
					    copy_pre->next = copy_cur;
				    else
					    copy_head = copy_cur;
				    copy_pre = copy_cur;

				    count++;
				    cur = cur->next;
			    }

			    copy_cur = copy_head;
			    cur = head;
			    count = 0;
			    while(copy_cur != NULL)
			    {
			        if(cur->random != NULL)
				        copy_cur->random = copy_v[m[v[count]]];
				    count++;
				    copy_cur = copy_cur->next;	    
				    cur = cur->next;
			    }
		    }

		    return copy_head;
	    }
};

typedef unsigned long long u64;

#include<cstdio>
void printV(RandomListNode* head)
{
	RandomListNode* cur = head;
	while(cur != NULL)
	{
		printf("label: %x cur: %llx next: %llx random: %llx \n", cur->label, (u64)cur, (u64)cur->next, (u64)cur->random);
		cur = cur->next;
	}
	printf("\n");
}
void generateTestData(RandomListNode** head, int num)
{
	RandomListNode* cur = NULL;
	RandomListNode* pre = NULL;
	vector<RandomListNode*> v;
	srand(time(0));
	for(int i = 0; i < num; i++)
	{
		cur = new RandomListNode(i);
		v.push_back(cur);
		if(pre != NULL)
			pre->next = cur;
		else
			*head = cur;
		pre = cur;
	}

	cur = *head;
	while(cur != NULL)
	{
		cur->random = v[rand()%num];
		cur = cur->next;
	}
}

int main(void)
{
	RandomListNode* head = NULL;
	generateTestData(&head, 5);
	printV(head);
	Solution s;
	printV(s.copyRandomList(head));
	return 0;

}
