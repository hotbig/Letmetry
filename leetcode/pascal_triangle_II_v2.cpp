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
                {
                    f *= (n--);
                    f /= (t+m-n);
                }
            }
            else
            {
                while(n > m)
                {
                    f *= (n--);
                    f /= (t+m-n);
                }
            }

           
            return f;

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
