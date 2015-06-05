#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution{
    public:
        bool containsDuplicate(vector<int>& nums)
        {
            int vec_size = 0;
            set<int> s;

            for(vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
            {
                vec_size++;
                s.insert(*it);
            }

            if(s.size() != vec_size)
                return true;
            else
                return false;
        }
};

int main()
{
    vector<int> vec;
    for(int i = 1; i <= 1; i++) vec.push_back(i);
    Solution s;

    cout<< (s.containsDuplicate(vec)?"dup":"no") << endl;
    
    
    vec.push_back(1);
    cout<< (s.containsDuplicate(vec)?"dup":"no") << endl;
    
    return 0;
}
