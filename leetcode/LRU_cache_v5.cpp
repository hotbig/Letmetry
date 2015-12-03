#include<iostream>
#include<list>
#include<string>
#include<map>

using namespace std;


class LRUCache{
    class V2C{
        public:
        int value;
        list<int>::iterator it;
    };

    int max;
    int count;
    multimap<int, V2C> key2Value2Count;
    list<int> count2Key;
    public:
        LRUCache(int capacity)
        {
            count = 0;
            count2Key.clear();
            key2Value2Count.clear();
            max = capacity;
        }

        int get(int key){ 
            multimap<int, V2C>::iterator it = key2Value2Count.find(key);
            if(it != key2Value2Count.end())
            {
                V2C& tmp = it->second;
#if 0
                pair <multimap<int,int>::iterator, multimap<int,int>::iterator> ret;
                ret = count2Key.equal_range(tmp.count);
                for(multimap<int,int>::iterator it=ret.first; it!=ret.second;++it)
                {
                    if(it->second == key)
                    {
                        count2Key.erase(it);
                        tmp.count++;
                        count2Key.insert(pair<int, int>(tmp.count, key));
                        break;
                    }
                }
#endif
                count2Key.erase(tmp.it);
                list<int>::iterator iit = count2Key.insert(count2Key.end(),key);
                tmp.it=iit;
#if 0
                cout << "cache hit" << key << endl;
#endif
                return tmp.value;
            }
            else
            {
        //        cout << "cache miss" << key << endl;
                return -1;
            }
        }

        void set(int key, int value)
        {
            multimap<int, V2C>::iterator it = key2Value2Count.find(key);

          if(it != key2Value2Count.end())
          {
              V2C& tmp = it->second;
              tmp.value = value;
              get(key);
                
           }
          else
            {
                if(count >= max)
                {
                    list<int>::iterator cit=count2Key.begin();

    //                cout << "cache eviction: " << *cit << endl;
                    key2Value2Count.erase(*cit);
                    count2Key.erase(cit);
                    count--;
                }
                
                list<int>::iterator iit = count2Key.insert(count2Key.end(),key);

                V2C tmp;
                tmp.value = value;
                tmp.it = iit;
      //          cout << "xxxx" <<*iit<<endl;
                    
                key2Value2Count.insert(pair<int, V2C>(key, tmp));
                count++;
            }
        }
};


class Solution{
    public:
        int lengthOfLastWord(string s){
        }
};


int main()
{
    LRUCache cache(2);
    cache.set(2,1);
    cache.set(2,2);
    cache.set(2,1);
    cache.set(2,1);
    
    return 0;
}
