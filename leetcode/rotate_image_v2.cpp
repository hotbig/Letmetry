#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        void rotate(vector<vector<int> >& v){
            int size = v.size();
            if(size > 1) {
                int edge = size - 1;
                for(int i=0; i < size/2; i++)
                {
                    edge = size - 1 - i;
                    for(int j = i; j <= edge-1; j++)
                    {
                        int a = v[j][edge];
                        v[j][edge] = v[i][j];

                        int b = v[edge][edge-j+i];
                        v[edge][edge-j+i]=a;

                        v[i][j] = v[edge-j+i][i];
                        v[edge-j+i][i]=b;
                    }
                } 
            }

        }
};

void printVV(vector<vector<int> >& vv)
{
    for(int i = 0 ; i < vv.size(); i++)
    {
        for(int j = 0; j < vv[i].size(); j++)
            cout << vv[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    Solution s;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    vector<int> v2;
    v2.push_back(5);
    v2.push_back(6);
    v2.push_back(7);
    v2.push_back(8);
    
    vector<int> v3;
    v3.push_back(9);
    v3.push_back(10);
    v3.push_back(11);
    v3.push_back(12);
    vector<int> v4;
    v4.push_back(13);
    v4.push_back(14);
    v4.push_back(15);
    v4.push_back(16);
    vector<vector<int> > vv;
    vv.push_back(v1);
    vv.push_back(v2);
    vv.push_back(v3);
    vv.push_back(v4);

    printVV(vv);
    s.rotate(vv);
    printVV(vv);
    return 0;
}
