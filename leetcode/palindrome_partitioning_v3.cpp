#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
    public:
	inline bool isParlindrome(string &s, int start, int end)
	{
        if(start == end) return true;
	    while(start<=end)
	    {
		    if(s[start] != s[end]) return false;
		    else {start++;end--;}
	    }
       
	    return true;
	}

    void dfs(int index, string &s, vector<vector<string> > &v, vector<string> path)
    {
        if(index == s.size()) { v.push_back(path); return; }

        for(int i = index; i < s.size(); i++)
        {
            if(isParlindrome(s, index, i))
            {
                path.push_back(s.substr(index, i-index+1));
                dfs(i+1, s, v, path);
                path.pop_back();
            }
        }
    }

	vector<vector<string> > partition(string s)
	{
        vector<vector<string> > v;
        if(s.empty()) return v;

        vector<string> path;
        dfs(0, s, v, path);
	    return v;
	}
};

void printVS(vector<vector<string> > &v)
{
    int sz = v.size();
    for(int i = 0; i < sz; i++)
    {
        int sz_s = v[i].size();
        for(int j = 0; j < sz_s; j++) cout << v[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

int main()
{
    Solution s;
    string ss("aaa");
    vector<vector<string> > v1 = s.partition(ss);
    //printVS(v1);
    return 0;
}
