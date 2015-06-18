#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:
        int trailingZeros(int n){
            int count = 0;

            for(int i = 1; i <= n; i++)
            {
                int j = i;
                while(!(j % 5))
                {
                    count++;
                    j /= 5;
                }
            }

            return count;
        }
};


int main()
{
    Solution s;

    cout << s.trailingZeros(1000000) << endl;
    
    return 0;
}
