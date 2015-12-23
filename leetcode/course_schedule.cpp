#include<iostream>
#include<vector>
#include<set>
#include<string>

using namespace std;

class Solution {
    class GraphGraph{
        public:
            int val;
            vector<int> next;
    };
    bool helper(GraphGraph g, vector<GraphGraph>& gr, vector<int>& res, int numCourses)
    {
        res.push_back(g.val);

        set<int> tmp(res.begin(), res.end());

        for(int i=0; i < res.size(); i++)
        {
            tmp.insert(res[i]);
        }

        for(int i=0; i < g.next.size(); i++)
        {
            tmp.insert(g.next[i]);
        }

        res.clear();
        for(set<int>::iterator it=tmp.begin(); it != tmp.end(); it++)
        {
            res.push_back(*it);
        }

        if(tmp.size() == numCourses)
        {
            return true;
        }
        else
        {
            for(int i = 0; i < g.next.size(); i++)
            {
                bool found = helper(gr[g.next[i]], gr, res, numCourses);
                if(found) return true;
            }
            return false;
        }
    }
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites) {
        vector<GraphGraph> gr; 
        vector<int> res;
        bool found = false;
        for(int i=0; i < numCourses; i++)
        {
            GraphGraph node;
            node.val = i;
            gr.push_back(node);
        }
        
        for(int i=0; i < prerequisites.size(); i++)
        {
            pair<int, int> tmp = prerequisites[i];
            gr[tmp.second].next.push_back(tmp.first);
        }
        if(gr.size() > 0)
            found = helper(gr[0], gr, res, numCourses);
        if(found) return res;
        else
        {
            vector<int> none;
            return none;
        }
    }
};

int main()
{
    Solution s;
    pair<int,int> p(1,0);
    pair<int,int> p1(2,0);
    //pair<int,int> p2(3,1);
    //pair<int,int> p3(3,2);
    vector<pair<int, int> > v;
    v.push_back(p);
    v.push_back(p1);
//    v.push_back(p2);
 //   v.push_back(p3);
    vector<int> ret=s.findOrder(4, v);
    cout << "xxxxxxxxxxxxxx "<< ret.size() << endl;
    for(int i = 0; i < ret.size(); i++)
        cout <<ret[i] << endl;
    
    
    return 0;
}
