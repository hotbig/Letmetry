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

			int a[]={1,2,3};

			for(int i=0; i < 3; i++){
				for(int j=0; j < 3;j++){
					for(int k=0; k < 3; k++){
						for(int m=0; m <3; m++){
							if((a[i]+a[j]+a[k]+a[m]) == len)
							{
								string s0 = s.substr(0, a[i]);
								if((a[i]>1 && s0[0] == '0') || atoi(s0.c_str())>255) continue;
								string s1 = s.substr(a[i], a[j]);
								if((a[j]>1 && s1[0] == '0') || atoi(s1.c_str())>255) continue;
								string s2 = s.substr(a[i]+a[j], a[k]);
								if((a[k]>1 && s2[0] == '0') || atoi(s2.c_str())>255) continue;
								string s3 = s.substr(a[i]+a[j]+a[k], a[m]);
								if((a[m]>1 && s3[0] == '0') || atoi(s3.c_str())>255) continue;

								results.push_back(s0+"."+s1+"."+s2+"."+s3);
							}
						}
					}
				}
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
#if 0
	int a[] = {1,1,2,3};
	s.permute(a, 0, 4, vv);
	printVV(vv);
#endif 
#if 1
	vector<string> results = s.restoreIpAddress("25525511125");
	printVS(results);
#endif 
    return 0;
}
