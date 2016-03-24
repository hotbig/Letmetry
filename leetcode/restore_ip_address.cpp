#include<iostream>
#include<cstdlib>
#include<string>
#include<vector>

using namespace std;

class Solution{
    public:
		void permute(int a[], int start, int len, vector<vector<int> >& vv)
		{
			if(start == (len-1)) 
			{
				vector<int> v(a, a+len);
				vv.push_back(v);
			}
			else
			{
				int pre = -1;
				for(int i = start; i < len; i++)
				{
					if(pre == a[i]||(start!=i && a[start]==a[i])) continue;
					pre = a[i];
					swap(a[start],a[i]);
					permute(a, start+1, len, vv);
					swap(a[start],a[i]);
				}
			}
		}

        vector<string> restoreIpAddress(string s){
			vector<string> results;
			size_t len = s.size();
			if(len < 4 || len > 12) return results;

			int a4[][4]   = {{1,1,1,1}};
			int a5[][4]   = {{1,1,1,2}};
			int a6[][4]   = {{1,1,1,3},{1,1,2,2}};
			int a7[][4]   = {{1,1,2,3},{1,2,2,2}};
			int a8[][4]   = {{1,2,2,3},{2,2,2,2},{1,1,3,3}};
		    int a9[][4]   = {{1,2,3,3},{2,2,2,3}};
			int a10[][4]  = {{1,3,3,3},{2,2,3,3}};
			int a11[][4]  = {{2,3,3,3}};
			int a12[][4]  = {{3,3,3,3}};
			
			typedef int (*type11)[4] ;
			struct { int num; type11 ptr;} ap[] = {
				{1,a4},{1,a5},{2,a6},{2,a7},{3,a8},{2,a9},{2,a10},{1,a11},{1,a12}};
			vector<vector<int> > vv;
		
			for(int i=0; i < ap[len-4].num; i++)
				permute(&(ap[len-4].ptr[i][0]), 0, 4, vv);

			for(int i=0; i<vv.size(); i++)
			{
				string s0 = s.substr(0, vv[i][0]);
				if((vv[i][0]>1 && s0[0] == '0') || atoi(s0.c_str()) > 255) continue;
				string s1 = s.substr(vv[i][0], vv[i][1]);
				if((vv[i][1]>1 && s1[0] == '0') || atoi(s1.c_str()) > 255) continue;
				string s2 = s.substr(vv[i][0]+vv[i][1], vv[i][2]);
				if((vv[i][2]>1 && s2[0] == '0') || atoi(s2.c_str()) > 255) continue;
				string s3 = s.substr(vv[i][0]+vv[i][1]+vv[i][2], vv[i][3]);
				if((vv[i][3]>1 && s3[0] == '0') || atoi(s3.c_str()) > 255) continue;

				results.push_back(s0+"."+s1+"."+s2+"."+s3);
			}

			return results;
      }
};

void printVV(vector<vector<int> >& vv)
{
	for(int i = 0; i < vv.size(); i++)
	{
		for(int j = 0; j < vv[i].size(); j++)
			cout << vv[i][j] << " ";
		cout << endl;
	}

}
void printVS(vector<string>& v)
{
	for(int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}

int main()
{
    Solution s;
	vector<vector<int> > vv;
#if 1
	int a[] = {1,1,2,3};
	s.permute(a, 0, 4, vv);
	printVV(vv);
#endif 
#if 0
	vector<string> results = s.restoreIpAddress("1111111");
	printVS(results);
#endif 
    return 0;
}
