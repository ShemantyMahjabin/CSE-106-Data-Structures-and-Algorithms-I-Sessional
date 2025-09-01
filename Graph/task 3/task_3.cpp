#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include<bits/stdc++.h>

using namespace std;
struct Rider
{
    int x;
    int y;
    int jump;

};
bool isPositionValid(int x,int y,int n,int m)
{
    if(x>=0 && x<n && y>=0 && y<m)
    {
        return true;
    }
    else
        return false;
}

vector<vector<int>>knightBFS(int x,int y,int maxSteps,int numRows,int numColm)
{
    vector<vector<int>>stepCounts(numRows,vector<int>(numColm,-1));
    vector<pair<int,int>>moves= {{1, 2}, {1, -2}, {2, 1}, {2, -1}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
    queue<pair<int,int>>q;
    q.push({x,y});
    stepCounts[x][y]=0;
    while(!q.empty())
    {
        int currentX=q.front().first;
        int currentY=q.front().second;
        q.pop();

        for(int i=0; i<moves.size(); i++)
        {
            int moveX=moves[i].first;
            int moveY=moves[i].second;

            int newX=currentX+moveX;
            int newY=currentY+moveY;

            if(isPositionValid(newX,newY,numRows,numColm) && stepCounts[newX][newY]==-1 && maxSteps>0)
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
    ifstream infile("in.txt");
    ofstream outfile("out.txt");
    int n,m,q;
    infile>>n>>m>>q;
    vector<Rider>riders(q);
    //vector<pair<pair<int,int>,int>>rider(q);
    for(int i=0; i<q; i++)
    {
        //infile>>rider[i].first.first>>rider[i].first.second>>rider[i].second;
        infile>>riders[i].x>>riders[i].y>>riders[i].jump;
    }
     int minTotalMoves=INT_MAX;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int minMoves=0;
            bool isValidLocation=true;

            for(int k=0; k<q; ++k)
            {
                const int riderX=riders[k].x;
                const int riderY=riders[k].y;
                const int riderMaxSteps=riders[k].jump;

                vector<vector<int>>moveCounts=knightBFS(riderX,riderY,riderMaxSteps,n,m);
                if(moveCounts[i][j]==-1)
                {
                    isValidLocation=false;
                    break;
                }
                minMoves+=ceil(moveCounts[i][j]+riderMaxSteps-1)/riderMaxSteps;
            }
            if(isValidLocation)
            {
                minTotalMoves=min(minTotalMoves,minMoves);
            }


        }
    }
    if (minTotalMoves != INT_MAX)
    {
        outfile<<minTotalMoves<<endl;
    }
    else
    {
        outfile<< -1<<endl;
    }
    infile.close();
    outfile.close();


    return 0;

}
