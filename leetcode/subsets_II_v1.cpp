#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//https://leetcode.com/discuss/14902/c-solution-and-explanation
class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
        vector<vector<int> > totalset = {{}};
        sort(S.begin(),S.end());
        for(int i=0; i<S.size();){
            int count = 0; // num of elements are the same
            while(count + i<S.size() && S[count+i]==S[i])  count++;
            int previousN = totalset.size();
            for(int k=0; k<previousN; k++){
                vector<int> instance = totalset[k];
                for(int j=0; j<count; j++){
                    instance.push_back(S[i]);
                    totalset.push_back(instance);
                }
            }
            i += count;
        }
        return totalset;
        }
};

void printVV(vector<vector<int> >& vv)
{
    for(int i = 0; i < vv.size(); i++)
    {
        for(int j = 0; j < vv[i].size(); j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    Solution s;
    vector<vector<int> > vv;
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vv=s.subsets(v);
    printVV(vv);
    
    return 0;
}
