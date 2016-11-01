#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
		int findLow(vector<int>& nums, int target, int low, int high)
		{
			int left = low;
			int right = high;
			int mid = left+(right-left)/2;
			while(left<=right)
			{
				if(nums[mid] == target)
				{
					if((mid-1)>=low && nums[mid-1] == target)
						right = mid - 1;
					else
						return mid;
				}
				else if(nums[mid]< target)
				{
					left = mid + 1;
				}

				mid = left+(right-left)/2;
			}
			return low;
		}

		int findHigh(vector<int>& nums, int target, int low, int high)
		{
			int left = low;
			int right = high;
			int mid = left+(right-left)/2;
			while(left<=right)
			{
				if(nums[mid] == target)
				{
					if((mid+1)<=high && nums[mid+1] == target)
						left = mid + 1;
					else
						return mid;
				}
				else if(nums[mid]> target)
				{
					right = mid - 1;
				}

				mid = left+(right-left)/2;
			}
			return high;
		}

        vector<int> searchRange(vector<int>& nums, int target){
			vector<int> range;
			int low = 0;
			int high = nums.size()-1;
			int mid = low + (high-low)/2;
			int rh = -1, rl = -1;

			while(low <= high)
			{
				if(nums[mid] < target)
				{
					low = mid + 1;
				}
				else if(nums[mid] > target)
				{
					high = mid - 1;
				}
				else
				{
					rh = findHigh(nums, target, mid, high);
					rl = findLow(nums, target, low, mid);
					break;
				}
				mid = low + (high-low)/2;
			}
			range.push_back(rl);
			range.push_back(rh);
			return range;
		}
};

void printV(vector<int>& nums)
{
	int i = 0;
	for(;i<nums.size();i++)
		cout << nums[i] << " ";
	cout << endl;
}

int main()
{
    Solution s;
	vector<int> nums;
	nums.push_back(8);
	vector<int> v = s.searchRange(nums, 8);
	printV(v);
    
    return 0;
}
