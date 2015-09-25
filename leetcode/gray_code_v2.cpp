#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        vector<int> grayCode(int n){
            vector<int> v;
            if(n == 0) 
            {
                v.push_back(0);
            }
            else if(n == 1)
            {
                v.push_back(0);
                v.push_back(1);
            }
            else
            {
                vector<int> t = grayCode(n-1);
                bool flip = false;
                for(int i = 0; i < t.size(); i++)
                {
                    if(flip == false)
                    {
                        v.push_back((t[i] << 1) + 0);
                        v.push_back((t[i] << 1) + 1);
                        flip = true;
                    }
                    else
                    {
                        v.push_back((t[i] << 1) + 1);
                        v.push_back((t[i] << 1) + 0);
                        flip = false;
                    }
                }
            }
            

            return v;
        }
};


void printV(vector<int>& v)
{
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << " " ;
    cout << endl;
}

int main()
{
    Solution s;
    vector<int> v=s.grayCode(3);
    printV(v);
    
    return 0;
}
