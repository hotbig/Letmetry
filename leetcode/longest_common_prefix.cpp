#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution{
    public:
        string longestCommonPrefix(vector<string>& strs){
            if(strs.size() == 0)
                return string("");

            string common(strs[0]);
            vector<string>::iterator it;

            for(it = strs.begin()+1; it != strs.end(); it++)
            {
                int comm = common.size();
                int newer  = (*it).size();

                if( comm > newer )
                {
                    common.erase(newer, comm-newer);
                    comm = newer;
                }
                
                for(int i=0; i < comm; i++)
                {
                    if(common[i] == (*it)[i])
                    {
                        continue;
                    }
                    else
                    {
                        common.erase(i, comm-i);
                        break;
                    }                      
                }

                if(common.size()==0)
                    break;
            }

            return common;
        }
};


int main()
{
    Solution s;

    vector<string> strs;
    strs.push_back("hee");
    strs.push_back("hello");
    strs.push_back("hxxxxxxxxxxxxxxxxxxxxxff");
    cout <<  s.longestCommonPrefix(strs) << endl;

    vector<string> strs1;
    strs1.push_back("hee");
    strs1.push_back("hello");
    strs1.push_back("xxff");
    cout <<  s.longestCommonPrefix(strs1) << endl;
    
    
    vector<string> strs2;
    strs2.push_back("aa");
    strs2.push_back("aa");
   
    strs2.push_back("a");
    cout <<  s.longestCommonPrefix(strs2) << endl;
    return 0;
}
