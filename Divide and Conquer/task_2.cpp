#include<iostream>
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;

minPlatform(vector<int>&a,vector<int>&d)
{
     int platform=1;
     int result=1;
     int i=1,j=0;
     sort(a.begin(),a.end());
     sort(d.begin(),d.end());
     do
     {
         if(a[i]<=d[j])
         {
             platform++;
             i++;
         }
         else if(a[i]>d[j])
         {
             platform--;
             j++;
         }
         if(platform>result)
         {
             result=platform;
         }
     }while(i<a.size()&& j<d.size());

     return result;

}


int main()
{
    int N;
    ifstream infile("in.txt");
    ofstream outfile("out.txt");
    infile>>N;
    vector<int>arrivaltime;
    vector<int>departuretime;
    int arrival;
    int departure;
    for(int i=0;i<N;i++)
    {
        infile>>arrival>>departure;
        arrivaltime.push_back(arrival);
        departuretime.push_back(departure);
    }
    int p=minPlatform(arrivaltime,departuretime);
    outfile<<p;
    infile.close();
    outfile.close();
    return 0;

}
