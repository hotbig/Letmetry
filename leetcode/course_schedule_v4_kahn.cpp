#include<iostream>
#include<vector>
#include<set>
#include<string>

using namespace std;

class Solution {
    class GraphGraph{
        public:
            int val;
            int in;
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
        set<int> myset;
        bool found = true;
        for(int i=0; i < numCourses; i++)
        {
            GraphGraph node;
            node.val = i;
            node.in = 0;
            gr.push_back(node);
        }
        
        for(int i=0; i < prerequisites.size(); i++)
        {
            pair<int, int> tmp = prerequisites[i];
            gr[tmp.first].in++;
            gr[tmp.second].next.push_back(tmp.first);
        }

        for(int i=0; i < gr.size(); i++)
        {
            if(gr[i].in == 0 )
            {
                myset.insert(gr[i].val);
            }
        }
       

        while(!myset.empty())
        {
            int tmp = *(myset.begin());
            myset.erase(myset.begin());
            res.push_back(tmp);

            for(int i = 0; i < gr[tmp].next.size(); i++)
            {
                (gr[gr[tmp].next[i]].in)--;
                if(gr[gr[tmp].next[i]].in == 0) 
                    myset.insert(gr[tmp].next[i]);
            }
        }

        for(int i = 0; i < gr.size(); i++)
        {
            if(gr[i].in != 0)
            {
                found = false;
                break;
            }
        }
        if(found == true && res.size() == numCourses)
        {
            return res;
        }
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
    vector<pair<int, int> > v;
//    v.push_back(p);
    vector<int> ret=s.findOrder(1, v);
    cout << "xxxxxxxxxxxxxx "<< ret.size() << endl;
    for(int i = 0; i < ret.size(); i++)
        cout <<ret[i] << endl;
    
    
    return 0;
}
