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
        ListNode* removeElements(ListNode* head, int val){
            ListNode* prev = NULL;
            ListNode* curr = head;

            while(curr != NULL)
            {
                if(curr->val == val)
                {
                    if(prev != NULL)
                    {
                        prev->next = curr->next;
                    }
                    else
                    {
                        head = curr->next;
                    }

                    ListNode* del = curr;
                    curr = curr->next;
                    delete del;
                }
                else
                {
                    prev = curr;
                    curr = curr->next;
                }
            }

            return head;
        }
};

int main(void)
{
    struct ListNode* head = new ListNode(6);
    struct ListNode* curr = head;
    curr->next = NULL;

    Solution s;
    head = s.removeElements(head, 6);

    curr = head;
    while(curr != NULL)
    {
        cout << curr->val << " ";
        curr=curr->next;
    }
    cout << endl;

    // delete all allocation //
    curr = head;
    while(curr != NULL)
    {
        struct ListNode* next = curr->next;
        delete curr;
        curr = next;
    }
    return 0;
}
