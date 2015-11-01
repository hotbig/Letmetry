#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool searchVector(vector<int>& vec, int target)
    {
        int low = 0, high=vec.size()-1;
        while(low <= high)
        {
            int mid=low+((high-low)>>1);
            if(vec[mid] == target) 
            {
                return true;
            }
            else if(vec[mid] < target)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        bool found = false;

        for(int i = 0; i < matrix.size(); i++)
        {
            if(target >= matrix[i][0])
            {
                found = searchVector(matrix[i], target);
                if(found) break;
            }
            else
            {
                break;
            }
        }

        return found;
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
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(4);
    v1.push_back(7);
    v1.push_back(11);
    v1.push_back(15);
    vv.push_back(v1);

    vector<int> v2;
    v2.push_back(2);
    v2.push_back(5);
    v2.push_back(8);
    v2.push_back(12);
    v2.push_back(19);
    vv.push_back(v2);
    
    vector<int> v3;
    v3.push_back(3);
    v3.push_back(6);
    v3.push_back(9);
    v3.push_back(16);
    v3.push_back(22);
    vv.push_back(v3);
    
    vector<int> v4;
    v4.push_back(10);
    v4.push_back(13);
    v4.push_back(14);
    v4.push_back(17);
    v4.push_back(24);
    vv.push_back(v4);
    
    vector<int> v5;
    v5.push_back(18);
    v5.push_back(21);
    v5.push_back(23);
    v5.push_back(26);
    v5.push_back(30);
    vv.push_back(v5);

    printVV(vv);
    cout << (s.searchMatrix(vv, 20)?"found":"not found") << endl;
    printVV(vv);
    
    return 0;
}
