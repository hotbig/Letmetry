#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<limits>
#include<cstdlib>

using namespace std;
bool icomp(long x, long y) {return x<y;}

class Solution{
    public:
        bool containsNearByAlmostDuplicate(vector<int>& v, int k, int t){
            multimap<long, int, bool(*)(long, long)> m(icomp);

            for(int i = 0; i < v.size(); i++)
            {
                  multimap<long, int, bool(*)(long, long)>::iterator lowit = m.lower_bound((long)v[i]-(long)(t));
                  multimap<long, int, bool(*)(long, long)>::iterator uppit = m.upper_bound((long)v[i]+(long)(t));

                  multimap<long, int, bool(*)(long, long)>::iterator it = lowit;
                  for(; it != m.end() && it != uppit; it++)
                  {
                      cout << (*it).second << "---" << endl;
                      if(abs((*it).second - i) <= k)
                      {
                          return true;
                      }
                  }
                  m.insert(pair<long, int>(v[i], i));
            }
            return false;
        }
};


int main()
{
    Solution s;
    vector<int> v;
    v.push_back(0);
    v.push_back(2147483647);
 //   v.push_back(8);
 //   v.push_back(10);
    cout << (s.containsNearByAlmostDuplicate(v, 1, 2147483647) ? "found": "Not found") << endl;;
    
    return 0;
}
