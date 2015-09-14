#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution{
    public:
	bool isParlindrome(string &s)
	{
	    int start = 0;
	    int end = s.size()-1;
	    while(start<=end)
	    {
		    if(s[start] != s[end]) return false;
		    else {start++;end--;}
	    }
       
	    return true;
	}

	vector<vector<string> > partition(string s)
	{
	    vector<vector<string> > v;
	    int size = s.size();
	    if(!size) return v;
	    
	    if(isParlindrome(s)) {
    		vector<string> vs; 
    		vs.push_back(s); 
    	 	v.push_back(vs);
	    }

	    for(int i = 1; i < size; i++)
	    {
    		string sub1(s, i, size-i);
    		string sub2(s, 0, i);
    		if(isParlindrome(sub2))
    		{
	    	     vector<vector<string> > ret = partition(sub1);
		         int ret_sz = ret.size();

		         for(int j = 0; j < ret_sz; j++)
		        {
			        vector<string> vs;
		            vs.push_back(sub2);
		            vs.insert(vs.end(), ret[j].begin(), ret[j].end());
		            v.push_back(vs);
		        }
		    }
	    }
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
    vector<vector<string> > v1 = s.partition("aaaaaaaaaaaaaaaaaa");
    //printVS(v1);
    return 0;
}
