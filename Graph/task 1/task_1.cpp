#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<vector>
using namespace std;


class Graph
{
    int vertices;
    vector<int>*adjacent;
    int *parent;
    int *distance;
    bool *visited;
    int length;


public:

    Graph(int vertices)
    {
        this->vertices=vertices;
        adjacent=new vector<int>[vertices];
        parent=new int[vertices];
        visited=new bool[vertices];
        distance=new int[vertices];
        for(int i=0; i<vertices; i++)
        {
            parent[i]=-1;
            distance[i]=INT_MAX;
            visited[i]=false;
        }
    }
    void addEdge(int vertices,int a)
    {
        adjacent[vertices].push_back(a);
    }
    void BFS(int s,int d)
    {
        for(int i=0; i<vertices; i++)
        {
            visited[i]=false;
            distance[i]=INT_MAX;
        }
        queue<int>q;
        q.push(s);
        distance[s]=0;
        visited[s]=true;
        while(!q.empty())
        {
            int u=q.front();

            if(u==d)
            {
                return;
            }
            q.pop();
            for(auto v:adjacent[u])
            {
                if(!visited[v])
                {
                    q.push(v);
                    visited[v]=true;
                    distance[v]=distance[u]+1;
                    parent[v]=u;

                }
            }
        }




    }

    void print(int s,int d)
    {
        ofstream outfile("out.txt");
        if(visited[d])
        {
            int u=d;
            length=0;
            while(u!=s)
            {
                length++;
                u=parent[u];
            }
            outfile<<length<<endl;
            printPath(s,d,outfile);

        }
        else
        {
            outfile<<-1;
        }
    }

    void printPath(int s,int d,ofstream &outfile)
    {
        vector<int>path;
        int u=d;
        while(u!=s)
        {
            path.push_back(u);
            u=parent[u];
        }
        path.push_back(s);
        for(int i=path.size()-1; i>=0; i--)
        {
            outfile<<path[i]<<" ";
        }

    }

};
int main()
{
    ifstream infile("in.txt");
    ofstream outfile("out.txt");
    int n,m;
    infile>>n>>m;
    Graph g(n);
    for(int i=0; i<m; i++)
    {
        int u,v;
        infile>>u>>v;
        g.addEdge(u,v);
    }
    int s,d;
    infile>>s>>d;
    g.BFS(s,d);
    g.print(s,d);
    return 0;

}

