#include<iostream>
#include<vector>
#include<string>
#include<limits>

using namespace std;

class Solution{
    public:
        int maxProfit(vector<int> &prices){
            int profit = 0;
            int size = prices.size();
            int low  = numeric_limits<int>::max();

            for(int i = 0; i < size; i++)
            {
                if(prices[i] < low) 
                {
                    low = prices[i];
                }
                else
                {
                    int cur = prices[i] - low;
                    if(cur > profit) profit = cur;
                }
            }

            return profit;
        }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(0);
    cout << s.maxProfit(v) << endl;

    v.push_back(2);
    cout << s.maxProfit(v) << endl;
    
    v.push_back(3);
    cout << s.maxProfit(v) << endl;
    
    v.push_back(1);
    cout << s.maxProfit(v) << endl;
    
    v.push_back(4);
    cout << s.maxProfit(v) << endl;
    
    v.push_back(7);
    cout << s.maxProfit(v) << endl;
    return 0;
}
