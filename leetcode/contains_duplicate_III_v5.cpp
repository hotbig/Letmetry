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
            multimap<int, int, bool(*)(int, int)> m(icomp);

            for(int i = 0; i < v.size(); i++)
            {
                  multimap<int, int, bool(*)(int, int)>::iterator lowit = m.lower_bound(v[i]-(t));
                  multimap<int, int, bool(*)(int, int)>::iterator uppit = m.upper_bound(v[i]+(t));

                  multimap<int, int, bool(*)(int, int)>::iterator it = lowit;
//                  cout << (*lowit).first << " " << (*uppit).first << endl;
//                  cout << (*lowit).second << " " << (*uppit).second << endl;
                  for(; it != m.end() && it != uppit; it++)
                  {
                      cout << (*it).second << "---" << endl;
                      if(abs((*it).second - i) <= k)
                      {
                          return true;
                      }
                  }
                  m.insert(pair<int, int>(v[i], i));
            }
            return false;
        }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(-1);
    v.push_back(-1);
 //   v.push_back(8);
 //   v.push_back(10);
    cout << (s.containsNearByAlmostDuplicate(v, 1, -1) ? "found": "Not found") << endl;;
    
    return 0;
}
