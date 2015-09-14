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

	vector<vector<string> > partition(string s)
	{
	    vector<vector<string> > v;
	    int size = s.size();
        if(size==1) {vector<string> vs; vs.push_back(s); v.push_back(vs);return v;}
	    
	    if(isParlindrome(s, 0, size-1)) {
    		vector<string> vs; 
    		vs.push_back(s); 
    	 	v.push_back(vs);
	    }

	    for(int i = 1; i < size; i++)
	    {
    		if(isParlindrome(s, 0, i-1))
    		{
    		    string sub1(s, i, size-i);
	    	    vector<vector<string> > ret = partition(sub1);
		        int ret_sz = ret.size();

                if(ret_sz > 0)
                {
        		    string sub2(s, 0, i);
	    	        for(int j = 0; j < ret_sz; j++)
		            {
		                ret[j].insert(ret[j].begin(), sub2);
		                v.push_back(ret[j]);
		            }
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
    string ss("aaaaaaaaaaaaaaaaaa");
    vector<vector<string> > v1 = s.partition(ss);
    //printVS(v1);
    return 0;
}
