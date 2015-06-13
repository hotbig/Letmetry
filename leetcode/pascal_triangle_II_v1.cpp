#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
        int combination(int n, int m)
        {
            long int f = 1;
            long int h = 1;
            int t = n-m;

            if(t > m)
            {
                while(n > t)
                    f *= (n--);
            
                while(m > 0)
                    h *= (m--);
            }
            else
            {
                while(n > m)
                    f *= (n--);

                while(t > 0)
                    h *= (t--);
            }

            return f/h;
        }

        vector<int> getRow(int rowIndex){
            
            vector<int> v;
            for(int i = 0; i <= rowIndex; i++)
            {
                v.push_back(combination(rowIndex, i));
            }
                
            return v;
        }

};


int main()
{
    Solution s;

    cout <<    s.combination(30, 15) << endl;
#if 1   
   
    vector<int> v =  s.getRow(30);


    for(int i = 0; i < v.size(); i++)
    {
           cout << v[i] << " ";
    }
    cout << endl;
    
#endif
    return 0;
}
