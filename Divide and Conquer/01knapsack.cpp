#include<iostream><i
#include<fstream>
using namespace std;
int p[100];
int w[100];
int dp[100][1000];


int maxCost(int n,int maxcap)
{
    if(n<0) return 0;
    else if(maxcap==0) return 0;
    else if(dp[n][maxcap]) return dp[n][maxcap];
    else{
        int ans=maxCost(n-1,maxcap);
        if(maxcap>=w[n])
        {
            ans=max(ans,maxCost(n,maxcap-w[n]+p[n]));

        }
        return dp[n][maxcap]=ans;
    }
}

int main()
{
    ifstream infile("in.txt");
    ofstream outfile("out.txt");
    int n,mxcap;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>w[i]>>p[i];
    }
    cin>>mxcap;
    cout<<maxCost(n-1,mxcap)<<endl;
}
