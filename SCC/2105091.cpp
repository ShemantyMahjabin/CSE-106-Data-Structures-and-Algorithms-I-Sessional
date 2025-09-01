#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 26;


vector<int> g[2 * N ];
vector<int> rg[2 * N ];
vector<int> topo;
vector<int>V;
int component[2 * N];


bool visit[2 * N ];

void addV(int a)
{
    for(auto v : V)
    {

        if(a == v)
        {
            return;
        }
    }
    V.push_back(a);
    if( a>=26)
    {
        a=a-N;
    }
    else if( a<26)
    {
        a=a+N;
    }
    V.push_back(a);

}
void addEdges(int a,int b)
{


    g[a].push_back(b);
    rg[b].push_back(a);
}



void dfs(int u)
{
    if(visit[u]) return;
    visit[u] = true;

    for (auto v : g[u])
    {
        if (!visit[v])
        {
            dfs(v);
        }
    }
    topo.push_back(u);
}

void rdfs(int u, int cur)
{
    if(visit[u]) return;
    visit[u] = true;
    component[u] = cur;

    for (auto v : rg[u])
    {
        if (!visit[v])
        {
            rdfs(v, cur);
        }
    }
}

void kosaraju()
{
    for(int i = 0; i< 2*N ; i++)
    {
        component[i] = -1;
    }
    for(int i = 0 ; i<2*N; i++)
    {
        visit[i] = false;

    }
    for (int i = 0; i < V.size(); i++)
    {
        if (!visit[V[i]])
        {
            dfs(V[i]);
        }
    }

    reverse(topo.begin(), topo.end());

    sort(V.begin(),V.end());
    for(int i = 0 ; i<2*N; i++)
    {
        visit[i] = false;

    }
    int cur = 0;
    for (auto u : topo)
    {

        if (component[u] == -1)
        {

            ++cur;
            rdfs(u, cur);
        }
    }

    for(int i=0; i<V.size()/2; i++)
    {
        if(component[V[i]]!= -1 && component[V[i]]==component[V[i+V.size()/2]])
        {
            cout<<"NO"<<endl;
            return;
        }

    }
    for(int i=0; i< V.size()/2; i++)
    {
        if(component[V[i]]>component[V[i+V.size()/2]])
        {
            cout<<char(i+'a')<<" true"<<endl;


        }
        else
            cout<<char(i+'a')<<" false"<<endl;
    }

}


int main()
{
    int n;
    cin>>n;
    getchar();

    for(int i=0; i<n; i++)
    {
        string clauses;
        getline(cin,clauses);
        int  var1,var2;

        if(clauses.size()==1)
        {
            var2=clauses[0]-'a';

            var1=clauses[0]-'a';

        }
        else if(clauses.size()==2)
        {
            if(clauses[0]=='~')
            {
                var2=clauses[1]-'a'+26;
                var1=clauses[1]-'a'+26;

            }
        }
        else if(clauses.size()==3)
        {
            var1=clauses[0]-'a';
            var2=clauses[2]-'a';

        }

        else if(clauses.size()==4)
        {
            if(clauses[0]=='~')
            {
                var1=clauses[1]-'a'+26;

                var2=clauses[3]-'a';

            }
            else
            {
                var1=clauses[0]-'a';
                var2=clauses[3]-'a'+26;

            }
        }
        else if(clauses.size()==5)
        {
            var1=clauses[1]-'a'+26;
            var2=clauses[4]-'a'+26;

        }


        if(clauses.size()<3)
        {
            addEdges((var1+26)%52,var2);
            addV(var1);
        }
        else
        {
            addV(var1);
            addV(var2);
            addEdges((var1+26)%52,var2);
            addEdges((var2+26)%52,var1);
        }

    }
    kosaraju();


    return 0;

}


