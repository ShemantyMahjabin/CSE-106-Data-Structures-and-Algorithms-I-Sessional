#include<iostream>
#include<bits/stdc++.h>
using namespace std;
struct Rider
{
    int x;
    int y;
    int jump;
    int max;
};
bool isValid(int x,int y,int n,int m)
{
    return x>=0 && x<n && y>=0 && y<m;
}

vector<vector<int>>knightBFS(int x,int y,int maxStep,int n,int m)
{
    vector<vector<int>>stepCounts(n,vector<int>(m,-1));
     vector<pair<int,int>>moves= {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
     queue<pair<int,int>>q;
     q.push({x,y});
     stepCounts[x][y]=0;
     while(!q.empty())
     {
         int currentX=q.front().first;
         int currentY=q.front().second;

        q.pop();

        for(int i=0;i<moves.size();i++)
        {
            int moveX=moves[i].first;
            int moveY=moves[i].second;

            int newX=currentX+moveX;
            int newY=currentY+moveY;
            if(isValid(newX,newY,n,m) && stepCounts[newX][newY]==-1 && maxStep>0)
            {
                stepCounts[newX][newY]=stepCounts[currentX][currentY]+1;
                q.push({newX,newY});
            }
        }
     }
     return stepCounts;
}


int main()
{
    int n,m,q;
    cin>>n>>m>>q;
    vector<Rider>riders(q);
    //vector<tuple<pair<int,int>,int,int>>riders(q);
    for(int i=0;i<q;i++)
    {
        //int x,y,k,h;
        cin>>riders[i].x>>riders[i].y>>riders[i].jump>>riders[i].max;
        //riders[i]=make_tuple(make_pair(x,y),k,h);
        //cin>>riders[i].first.first>>riders[i].first.second>>riders[i].second>>riders[i].third;
    }

    int minTotalValue= INT_MAX;

    for(int i=0;i<n;i++)
    {

        for(int j=0;j<m;j++)
        {
            bool isValidLocation=true;
            int minvalue=0;
            for(int k=0;k<q;k++)
            {

                const int riderX=riders[k].x;
                const int riderY=riders[k].y;
                const int riderMaxSteps=riders[k].jump;
                const int highestMove=riders[k].max;

                vector<vector<int>>moveCounts=knightBFS(riderX,riderY,riderMaxSteps,n,m);
                if(moveCounts[i][j]==-1)
                {
                    isValidLocation=false;
                    break;
                }

                if((moveCounts[i][j]+riderMaxSteps-1)/riderMaxSteps>highestMove)
                {
                    isValidLocation=false;
                    break;
                }
                minvalue+=(moveCounts[i][j]+riderMaxSteps-1)/riderMaxSteps;



            }
            //cout<<minvalue<<endl;
            if(isValidLocation)
            {
                minTotalValue=min(minTotalValue,minvalue);
            }
        }
    }
    if(minTotalValue!=INT_MAX)
    {
        cout<<minTotalValue<<endl;
    }
    else
    {
        cout<<-1;
    }

    return 0;


}

