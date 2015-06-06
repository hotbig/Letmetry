#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

class Solution{
    public:
        void parse(string s, map<char, vector<int>* > &m, string &u)
        {
            int i = 0;
            int size = s.size();

            for(;i < size; i++)
            {
                vector<int> *v = m[s[i]];
                if(v == NULL)
                {
                    v = new vector<int>;
                    m[s[i]] = v;
                }
                v->push_back(i);

                if(v->size() == 2)
                    u = u.append(1, s[i]);
            }
        }
        void clean(string s, map<char, vector<int>* > &m)
        {
            if(s != NULL)
            {
                for(int i; i < s.size(); i++)
                {
                    vector<int>* v = m[s[i]];
                    if( v!= NULL)
                        delete v;
                }
            }       
        }

        bool isIsomorphic(string s, string t){
            map<char, vector<int>* > m_s;
            map<char, vector<int>* > m_t;
            string u_s = "";
            string u_t = "";
            bool isIsomo = true;

            parse(s, m_s, u_s);
            parse(t, m_t, u_t);

            int s_s = u_s.size();
            int s_t = u_t.size();

//            cout << "--" << s_s <<  "  " << s_t << endl;
            if( s_s == s_t )
            {
                for(int i = 0; i < s_s; i++)
                {
                    vector<int>* vp_s = m_s[u_s[i]];
                    vector<int>* vp_t = m_t[u_t[i]];

                    int v_s_s = (*vp_s).size();
                    int v_s_t = (*vp_t).size();

                    if(v_s_s != v_s_t)
                    {
                        isIsomo = false;
                        goto end;
                    }
                    else
                    {
                        for(int j = 0; j < v_s_s; j++)
                        {
                //            cout << (*vp_s)[j] << " " << (*vp_s)[j] <<endl;
                            if((*vp_s)[j] != (*vp_t)[j])
                            {
                                isIsomo = false;
                                goto end;
                            }
                        }
                    }
                }
                        
            }
            else
            {
                isIsomo = false;
            }

end:

           clean(s, m_s);
           clean(t, m_t);
           return isIsomo;
        }

};


int main()
{
    Solution s;

    string s1="aa";
    string s2="bb";
    cout << (s.isIsomorphic(s1, s2)?"YES":"NO")<<endl;

    string s3="foo";
    string s4="bar";
    cout << (s.isIsomorphic(s3, s4)?"YES":"NO")<<endl;
    
    string s5="paper";
    string s6="title";
    cout << (s.isIsomorphic(s5, s6)?"YES":"NO")<<endl;
    
    string s7="p";
    string s8="t";
    cout << (s.isIsomorphic(s7, s8)?"YES":"NO")<<endl;
    
    string s9="pp";
    string s10="tt";
    cout << (s.isIsomorphic(s9, s10)?"YES":"NO")<<endl;
    
    string s11="aabbccaaooooooo75abcdef75";
    string s12="bbccaabbqqqqqqq75bcadef75";
    cout << (s.isIsomorphic(s11, s12)?"YES":"NO")<<endl;
    
    string s13="aabbccaaooooooo75abcdef75";
    string s14="bbccaabbqqqqqqq78bcadef75";
    cout << (s.isIsomorphic(s13, s14)?"YES":"NO")<<endl;
    
    string s15="";
    string s16="";
    cout << (s.isIsomorphic(s15, s16)?"YES":"NO")<<endl;
#if 0
    map<char, vector<int>* > m;
    string u="";

    s.parse(str, m, u);

    cout << u << endl;
    for(int i = 0; i < u.size(); i++)
    {
        vector<int>* v = m[u[i]];
        cout << (*v).size() <<endl;
        vector<int>::iterator it = (*v).begin();
        for(;it<(*v).end();it++)
        {
            cout << *it ;
        }
        
        cout << endl;
    }
            
   for(int i; i < str.size(); i++)
   {
       delete (m[str[i]]);
   }       

#endif
    
    return 0;
}
