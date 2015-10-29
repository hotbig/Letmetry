#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
    int rangeBitwiseAnd(int m, int n){
        if(m==n) return m;
        if(m==0) return 0;
        if((n-m)==1) return (n&m);
        
        if((n>>1) >= m) return 0;
        else
        {
            int i = 1; 
            int j = 1;
            int a = m;
            int b = n;
            m=m>>1;
            while(m>0)
            {
                m = m>>1; 
                i = i<<1; 
            }
            n=n>>1;
            while(n>0)
            {
                n = n>>1;
                j = j<<1;
            }
   
            if(j != i) 
                return 0; 
            else
            {
                int tmp = rangeBitwiseAnd(a&(i-1), b&(j-1));
                return (i|tmp);
            }
        }
    }
};

int main()
{
    Solution s;
    cout << s.rangeBitwiseAnd(12, 14) << endl;

    
    return 0;
}
