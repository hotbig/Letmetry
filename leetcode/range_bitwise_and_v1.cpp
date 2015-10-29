#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        int rangeBitwiseAnd(int m, int n){
            if((n>>1) >= m) return 0;
            else
            {
                int i = 1; 
                m=m>>1; 
                while(m>0)
                {
                    m = m>>1;
                    i = i<<1;
                }
                
                return (i|rangeBitwiseAnd(m&(i-1), n&(i-1)));
            }
        }
};


int main()
{
    Solution s;
    cout << s.rangeBitwiseAnd(5, 7) << endl;

    
    return 0;
}
