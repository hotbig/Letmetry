#include<iostream>
#include<vector>
#include<string>
#include<limits>

using namespace std;

class Solution{
    public:
        int maxProfit(vector<int> &prices){
            int max = 0;
            int size = prices.size();

            if(size > 1)
            {
                int prevMin = numeric_limits<int>::max();
                int prevMax = 0;
                bool findNextMin = true;
                int curr = 0; ///1 2 3
                for(int i = 0; i < size; i++)
                {
                    if(findNextMin)
                    {
                        if(prices[i] <= prevMin) // continure to find min price
                        {
                            prevMin = prices[i];
                        }
                        else
                        {
                            findNextMin = false; // buy in price:prevMin 
                            prevMax = prices[i];
                            curr=curr-prevMin;
                            if(i == size -1) max=curr+prevMax; // if last, sell out
                        }
                    }
                    else
                    {
                        if(prices[i] >= prevMax) // contiune to find max price
                        {
                            prevMax = prices[i];
                            if(i == size -1) max=curr+prevMax; // if last, sell out
                        }
                        else
                        {
                            findNextMin = true;  // sell out max
                            prevMin = prices[i];
                            curr = curr+prevMax;  
                            max = curr;
                        }
                    }
                }
            }

            return max;
        }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(1);
    cout << s.maxProfit(v) << endl;

    v.push_back(2);
    cout << s.maxProfit(v) << endl;
    
    v.push_back(3);
    cout << s.maxProfit(v) << endl;
    
    v.push_back(1);
    cout << s.maxProfit(v) << endl;
    
    v.push_back(4);
    cout << s.maxProfit(v) << endl;
    return 0;
}
