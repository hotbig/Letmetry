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
                    m.insert(pair<int, int>(v[i], i));
                    multimap<int, int, bool(*)(int, int)>::iterator it = m.find(v[i]);
                    multimap<int, int, bool(*)(int, int)>::iterator prev = it--; 
                   
                    if(prev!=m.begin())
                    {
                        cout << (*prev).first << endl;
                        cout << (*it).first << endl;
                        cout << (*prev).second << endl;
                        cout << (*it).second << endl;
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
                        cout <<"=== " << (*prev).first << endl;
                        cout << (*post).first << endl;
                        cout <<"*** " << (*prev).second << endl;
                        cout << (*post).second << endl;
                        if(((*(prev)).first-(*post).first) <=t &&
                           abs((*(prev)).second-(*post).second) <=k)
                        {
                            found = true;
                            break;
                        }
                    }
            }
            return found;
        }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
 //   v.push_back(8);
 //   v.push_back(10);
    cout << (s.containsNearByAlmostDuplicate(v, 1, 0) ? "found": "Not found") << endl;;
    
    return 0;
}
