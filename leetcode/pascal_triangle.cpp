#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
        int c(int n, int m)
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

        vector<vector<int> > generate(int numRows){
            vector<vector<int> > vv;
            for(int i = 0; i < numRows; i++)
            {
                vector<int> v;
                for(int j = 0; j <= i; j++)
                {
                   v.push_back(c(i, j));
                }
                vv.push_back(v);
            }
            return vv;
        }

};


int main()
{
    Solution s;

//    cout <<    s.c(21, 20) << endl;
#if 1   
   
    vector<vector<int> > v =  s.generate(125);


    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < (v[i]).size(); j++)
            cout << v[i][j] ;

        cout << endl;
    }
    
#endif
    return 0;
}
