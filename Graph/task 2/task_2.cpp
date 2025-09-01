#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<vector>
using namespace std;


class Graph
{
    int vertices;
    vector<int>*adjacent;
    bool *visited;
    vector<int> path;

public:

    Graph(int vertices)
    {
        this->vertices=vertices;
        adjacent=new vector<int>[vertices];
        visited=new bool[vertices];
        for(int i=0; i<vertices; i++)
        {
            visited[i]=false;
        }
    }

    void addEdge(int u,int v)
    {
        adjacent[u].push_back(v);
    }

    bool DFS(int s,int d)
    {
        visited[s] = true;
        path.push_back(s);

        if (s == d) {
            return true;
        }

        for (int v : adjacent[s]) {
            if (!visited[v]) {
                if(DFS(v, d)) {
                    return true;
                }
            }
        }

        path.pop_back();//path  na pele current node ta pop kore
        return false;
    }

   void printPath(ofstream &outfile) {
    if (!path.empty()) {
        int pathLength = path.size();
        outfile << pathLength-1 << endl;
        for (int i = 0; i < pathLength; ++i) {
            outfile << path[i] << " ";
        }
    } else {
        outfile << -1;
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
    if(g.DFS(s,d)){
        g.printPath(outfile);
    }

    return 0;
}
