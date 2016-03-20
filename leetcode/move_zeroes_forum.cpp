#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        int moveZeroes(vector<int> &nums){
		int writePos = 0;

		for(int i = 0; i < nums.size(); i++)
		{
			if(nums[i] != 0)
			{
				nums[writePos++] = nums[i];
			}
		}

		for(int i = writePos; i < nums.size(); i++)
		{
			nums[i] = 0;
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
    v.push_back(2);
    s.moveZeroes(v);

    printV(v);
    
    return 0;
}
