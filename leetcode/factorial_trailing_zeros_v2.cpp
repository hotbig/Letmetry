#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:
        int trailingZeros(int n){
            int count = 0;
            int j = 5;

            for(int i = 1; (j=i*5) <= n; i++)
            {
                int k = j;
                while(!(k % 5))
                {
                    count++;
                    k /= 5;
                }
            }

            return count;
        }
};


int main()
{
    Solution s;

    cout << s.trailingZeros(10000000) << endl;
    
    return 0;
}
