#include<iostream>
#include<queue>
#include<string>

using namespace std;

typedef struct  ListNode{
	int val;
	ListNode* next;
	ListNode* prev;
}ListNode;

class MedianFinder{
	priority_queue<int> smaller;
	priority_queue<int> larger;
	
    public:
		MedianFinder(){
		}
#if 1
		~MedianFinder(){
		}
#endif

        void addNum(int num){
			if(larger.empty()) {
				larger.push(-1*num);
				return;
			}
			
			if(larger.size() == smaller.size())
			{
				if(num >= smaller.top()) 
					larger.push(num*(-1));
				else
				{
					larger.push(smaller.top()*(-1));
					smaller.pop();
					smaller.push(num);
				}
			}
			else
			{
				if(-1*num < larger.top()) 
				{
					smaller.push(larger.top()*(-1));
					larger.pop();
					larger.push(-1*num);
				}
				else
				{
					smaller.push(num);
				}
			}

        }

		double findMedian(){
			if(larger.size() == smaller.size())
			{
				return (double)(-1*larger.top()+smaller.top())/2;
			}
			else
			{
				return -1*larger.top();
			}


		}

}; 


int main()
{
	priority_queue<int> mypq;

	mypq.push(30);
	mypq.push(40);
	mypq.push(50);
	mypq.push(60);
	while(!mypq.empty())
	{
		cout << mypq.top() << endl;
		mypq.pop();
	}


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
