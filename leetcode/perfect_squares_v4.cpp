#include<iostream>
#include<vector>
#include<cmath>
#include<string>

using namespace std;
#define min(a,b) ((a)>(b)?(b):(a))
//https://leetcode.com/discuss/62526/an-easy-understanding-dp-solution-in-java
class Solution{
    public:
        int numSquares(int n){
            vector<int> vec;
            vec.push_back(0);

            for(int i = 1; i <= n; ++i){
                int min = n;
                int j = 1;
                while(i - j*j >= 0){
                    min = min(min, vec[i-j*j]+1);
                   ++j;
                }
                vec.push_back(min);
            }
           return vec[n]; 
        }
};


int main()
{

    Solution s;
    int i = 111188;
    cout << i << ": " << s.numSquares(i) << endl;
    
    return 0;
}
