#include<iostream>
#include<vector>
#include<set>
#include<string>

using namespace std;

class Solution {
    class GraphGraph{
        public:
            int val;
            int visited;
            int removed;
            vector<int> next;
    };
    bool helper(GraphGraph &g, vector<GraphGraph>& gr, vector<int>& res, int numCourses)
    {
        if(g.visited == 1) return false;

        if(g.removed == 0)
        {
            g.visited = 1;
            for(int i = 0; i < g.next.size(); i++)
            {
                bool found = helper(gr[g.next[i]], gr, res, numCourses);
                if(found == false) return false;
            }
            g.removed = 1;
            g.visited = 0;
            res.insert(res.begin(), g.val);
        }
        return true;
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
            node.visited = 0;
            node.removed = 0;
            gr.push_back(node);
        }
        
        for(int i=0; i < prerequisites.size(); i++)
        {
            pair<int, int> tmp = prerequisites[i];
            gr[tmp.second].next.push_back(tmp.first);
        }
        for(int i=0; i < gr.size(); i++)
        {
            if(gr[i].removed == 0 )
            {
                found = helper(gr[i], gr, res, numCourses);
                if(found == false) break;
            }
        }
#if 1
        if(res.size() == numCourses ) return res;
        else
        {
            vector<int> none;
            return none;
        }
#endif 
    }
};

int main()
{
    Solution s;
    pair<int,int> p(1,0);
    pair<int,int> p1(2,0);
    pair<int,int> p2(3,1);
    pair<int,int> p3(3,2);
    vector<pair<int, int> > v;
    v.push_back(p);
    v.push_back(p1);
    v.push_back(p2);
    v.push_back(p3);
    vector<int> ret=s.findOrder(4, v);
    cout << "xxxxxxxxxxxxxx "<< ret.size() << endl;
    for(int i = 0; i < ret.size(); i++)
        cout <<ret[i] << endl;
    
    
    return 0;
}
