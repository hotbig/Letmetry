#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        int moveZeroes(vector<int> &nums){
		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] == 0)
			{
				for(int j = i+1; j < nums.size(); j++)
				{
					if(nums[j] != 0)
					{
						int tmp = nums[i];
						nums[i] = nums[j];
						nums[j] = tmp;
						break;
					}
				}
			}
		}
        }
};

void printV(vector<int> &v)
{
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
}

int main()
{
    Solution s;
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    s.moveZeroes(v);

    printV(v);
    
    return 0;
}
