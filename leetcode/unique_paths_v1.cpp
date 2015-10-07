#include<iostream>
#include<vector>
#include<string>
#include<limits>

using namespace std;

class Solution{
    public:
        int uniquePaths(int m, int n){
            if(m<1  || n < 1) return 0;
            if(m==1 || n== 1) return 1;
            if(m==2 && n== 2) return 2;
            
            return (uniquePaths(m-1, n))+(uniquePaths(m, n-1));
        }
};


int main()
{
    Solution s;
    
    cout << s.uniquePaths(20,20) << endl;
    return 0;
}
