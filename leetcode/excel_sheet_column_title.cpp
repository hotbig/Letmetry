#include<iostream>
#include<string>

using namespace std;

class Solution{
    public:
        string convertToTitle(int n){
            string s="";
            if(n <= 0) return s;

            s.insert(0, 1, ((n-1)%26) + 'A');
            while((n = (n-1)/26) > 0)
            {
                s.insert(0, 1, ((n-1)%26) + 'A');
            }
            
            return s;
        }
};


int main()
{
    Solution s;
    int start = 0*26 + 1;
    int loop = start + 26;
    for(int i = start ; i < loop; i++)
        cout << s.convertToTitle(i) << endl;
    
    return 0;
}
