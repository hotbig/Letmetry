#include<iostream>
#include<map>
#include<string>
#include<vector>

using namespace std;

typedef struct UndirectedGraphNode{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    public:
    UndirectedGraphNode(int x):label(x){}
}UndirectedGraphNode;

class Solution{
    public:
        UndirectedGraphNode* helper(UndirectedGraphNode* node, map<int, UndirectedGraphNode*>& hash){
            UndirectedGraphNode* clone = NULL;
  
            if(node != NULL)
            {
                map<int , UndirectedGraphNode*>::iterator it=hash.find(node->label);
                if(it == hash.end())
                {
                    clone = new UndirectedGraphNode(node->label);
                    hash[clone->label]=clone;
//                    cout << node->label << endl;

                    for(int i=0; i<(node->neighbors).size();i++)
                    {
                        clone->neighbors[i]=helper((node->neighbors)[i], hash);
                    }
                }
                else
                {
                    return hash[node->label];
                }
            }

            return clone;
        }

        UndirectedGraphNode* cloneGraph(UndirectedGraphNode* node){
           map<int, UndirectedGraphNode*> hash;
           return helper(node, hash);
        }
};


int main()
{
    Solution s;
    UndirectedGraphNode* n1= new UndirectedGraphNode(0);
    UndirectedGraphNode* n2= new UndirectedGraphNode(1);
    UndirectedGraphNode* n3= new UndirectedGraphNode(2);
    n1->neighbors.push_back(n2); n1->neighbors.push_back(n3);
    n2->neighbors.push_back(n1); n2->neighbors.push_back(n3);
    n3->neighbors.push_back(n1); n3->neighbors.push_back(n2);
    n3->neighbors.push_back(n3);

    UndirectedGraphNode* clone=s.cloneGraph(n1);

    cout << clone->label<< endl;
    cout << clone->neighbors[0]->label<< endl;
    cout << clone->neighbors[1]->label<< endl;



    
    return 0;
}
