#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<limits>
#include<cstdlib>

using namespace std;
        bool icomp(int x, int y) {return x<y;}

class Solution{
    public:
        bool containsNearByAlmostDuplicate(vector<int>& v, int k, int t){
            bool (*fn_pt)(int, int) = icomp;
            multimap<int, int, bool(*)(int, int)> m(fn_pt);
            bool found = false;

            for(int i = 0; i < v.size(); i++)
            {
                if(m.find(v[i]) == m.end())
                {
                    m.insert(pair<int, int>(v[i], i));
                    multimap<int, int, bool(*)(int, int)>::iterator it = m.find(v[i]);
                    multimap<int, int, bool(*)(int, int)>::iterator prev = it--; 
                    if(prev!=m.begin())
                    {
                        if(((*prev).first-(*(it)).first) <=t && 
                            abs((*prev).second-(*(it)).second) <=k)
                        {
                            found = true;
                            break;
                        }
                    }

                    multimap<int, int, bool(*)(int, int)>::iterator post = prev++;
                    multimap<int, int, bool(*)(int, int)>::iterator zen = prev;
                    if((prev)!=m.end())
                    {
                        if(((*(prev)).first-(*post).first) <=t &&
                           abs((*(prev)).second-(*post).second) <=k)
                        {
                            found = true;
                            break;
                        }
                    }
                }
                else
                {
                    found = true;
                    break;
                }
                
            }
            return found;
        }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(4);
    v.push_back(2);
    v.push_back(-2);
 //   v.push_back(8);
 //   v.push_back(10);
    cout << (s.containsNearByAlmostDuplicate(v, 2, 1) ? "found": "Not found") << endl;;
    
    return 0;
}
