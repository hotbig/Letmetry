#include<iostream>
#include<string>

using namespace std;

typedef struct  ListNode{
	int val;
	ListNode* next;
	ListNode* prev;
}ListNode;

class MedianFinder{
	ListNode* head;
	int count;
	ListNode* median;
	double median_val;
	
    public:
		MedianFinder(){
			head = NULL;
			median = NULL;
			count = 0;
		}
#if 1
		~MedianFinder(){
			ListNode* cur=head;
			ListNode* next=head->next;
			while(next != NULL)
			{
				delete cur;
				cur = next;
				next = cur->next;
			}
			delete cur;
		}
#endif

        void addNum(int num){
			ListNode* ln_ptr = new ListNode();
			if(ln_ptr != NULL)
			{
				ln_ptr->val = num;
				ln_ptr->next = NULL;
				ln_ptr->prev = NULL;

				ListNode* pre = NULL;
				ListNode* cur = head;
				if(median != NULL)
				{
					if(num >= median->val)
					{
						pre=median->prev;
						cur=median;
					}
				}
				while(cur!= NULL && num > cur->val)
				{
					pre = cur;
					cur = cur->next;
					
				}
				
				if(pre == NULL)
				{
					ln_ptr->next = head;
					if(head != NULL)
						head->prev = ln_ptr;
					head = ln_ptr;
				}
				else
				{
					pre->next = ln_ptr;
					ln_ptr->prev = pre;
					ln_ptr->next = cur;
					if(cur != NULL)
						cur->prev = ln_ptr;
				}

				if(median == NULL)
				{
					median = head;
					median_val = median->val;
				}
				else
				{
					if(median->val >= num)
					{
						if(count % 2){
							median_val = ((double)median->val+median->prev->val)/2;
							median = median->prev;
						}
						else
						{
							median_val = median->val;
						}
					}
					else
					{
						if(count % 2){
							median_val = ((double)median->val+median->next->val)/2;
						}
						else
						{
							median_val = median->next->val;
							median = median->next;
						}
					}
				}

				count++;
			}
        }

		double findMedian(){

			return median_val;

		}

}; 


int main()
{

    MedianFinder mf;
	mf.addNum(-1);
	cout << mf.findMedian() << endl;
    
	mf.addNum(-2);
	cout << mf.findMedian() << endl;
	mf.addNum(-3);
	cout << mf.findMedian() << endl;
	mf.addNum(-4);
	cout << mf.findMedian() << endl;
	mf.addNum(-5);
	cout << mf.findMedian() << endl;
    return 0;
}
