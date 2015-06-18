#include<iostream>
#include<string>
#include<limits>

using namespace std;

class Solution{
    public:
        int trailingZeros(int n){
            return n == 0 ? 0 : n / 5 + trailingZeros(n/5);
        }
};


int main()
{
    Solution s;

    cout << s.trailingZeros(1000000) << endl;
    
    return 0;
}

