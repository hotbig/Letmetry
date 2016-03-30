#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
	    struct Data;
			Data* data;
	public:
				Iterator(const vector<int>& nums);
					Iterator(const Iterator& iter);
						virtual ~Iterator();
							// Returns the next element in the iteration.
							int next();
								// Returns true if the iteration has more elements.
								bool hasNext() const;
};



class PeekingIterator : public Iterator {
	int m_next;
	bool m_hasnext;
	public:

			PeekingIterator(const vector<int>& nums) : Iterator(nums) {

				m_hasnext = Iterator::hasNext();
				if(m_hasnext) m_next = Iterator::next();
				
					    // Initialize any member here.
					    // **DO NOT** save a copy of nums and manipulate it directly.
					    // You should only use the Iterator interface methods.
					    
					}

			    // Returns the next element in the iteration without advancing the iterator.
				int peek() {
					return m_next;
					
					        
						}

					// hasNext() and next() should behave the same as in the Iterator interface.
					// Override them if needed.
					int next() {
						int t=m_next;
						m_hasnext = Iterator::hasNext();
						if(m_hasnext) m_next = Iterator::next();
						
					}

							    
							

						bool hasNext() const {
							return m_hasnext;
								    
								}
};

int main()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	PeekingIterator pi(v);
	cout << pi.peek()<< endl;
    
    return 0;
}
