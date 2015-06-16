#include<iostream>
#include<vector>
#include<limits>
#include<string>

using namespace std;

class Solution{
    public:
        int strToNumVer(string s, vector<int>& v)
        {  
            int num = 0;
            int max = numeric_limits<int>::max()/10 + 1;
            for(int i = 0; i < s.size(); i++)
            {
                if(s[i] == '.')
                {
                    v.push_back(num);
                    num = 0;
                }
                else if(s[i] >= '0' && s[i] <= '9')
                {
                    if(num > max) return -1;
                    num = num*10+(s[i]-'0');
                }
                else
                {
                    return -1;
                }   
            } 

            v.push_back(num);
            return 0;
        }

        int compareVersion(string version1,string version2){
            vector<int> v1;
            vector<int> v2;
            int i = 0;
            int ret = 0;

            if( strToNumVer(version1, v1) == -1) return 0;
            if( strToNumVer(version2, v2) == -1) return 0;

            if(v1.size() > v2.size())
            {
                for(int i = 0; i < v2.size(); i++)
                {
                    if(v1[i] > v2[i]) return 1;
                    else if(v1[i] < v2[i]) return -1;
                }
                for(int i = v2.size(); i < v1.size(); i++)
                    if(v1[i] > 0) return 1;
            }
            else if(v1.size() <= v2.size())
            {
                for(int i = 0; i < v1.size(); i++)
                {
                    if(v1[i] > v2[i]) return 1;
                    else if(v1[i] < v2[i]) return -1;
                }
                for(int i = v1.size(); i < v2.size(); i++)
                    if(v2[i] > 0) return -1;
            }

            return ret;
        }
};


int main()
{
    Solution s;
//    cout <<  s.compareVersion("1.1", "1.2") << endl;
//    cout <<  s.compareVersion("1.3", "1.2") << endl;
    cout <<  s.compareVersion("1.333333", "2.2") << endl;
    cout <<  s.compareVersion("1.111111111.3", "1.2") << endl;
    cout <<  s.compareVersion("1", "1.1") << endl;
    cout <<  s.compareVersion("0.1", "0.0.1") << endl;
    cout <<  s.compareVersion("0.0", "0.0.0") << endl;
    cout <<  s.compareVersion("0.0", "0.0.00000") << endl;
//    cout <<  s.compareVersion("1.3", "1.2") << endl;
    
    return 0;
}
