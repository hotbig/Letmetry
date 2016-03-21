#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
    public:
	vector<string> combine(vector<string> &com, string b)
	{
		vector<string> ret;
		if(b.size() == 0) return com;
		for(int i = 0; i < com.size();i++)
		{
			for(int j = 0; j < b.size(); j++)
			{
				string s = com[i];
				//s.insert(s.end(), 1, b[j]);
				s = s+b[j];
				ret.push_back(s);
			}
		}

		return ret;
	}

        vector<string> letterCombinations(string digits){
		vector<string> results;
		if(digits.size() == 0) return results;
		string phone[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		size_t num = sizeof(phone)/sizeof(string);

		vector<string> phone_letters(phone, phone+num);

		results.push_back("");


		for(int i = 0; i< digits.size(); i++)
		{
			results = combine(results, phone_letters[digits[i]-'0']);
		}

		return results;
        }
};

void printV(vector<string> &v)
{
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}


int main()
{
    Solution s;

    vector<string> v=s.letterCombinations("0123456789");
    printV(v);
    



    
    return 0;
}
