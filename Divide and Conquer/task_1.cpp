#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;
pair<int, int> mid;
class Point
{
public:
    int x, y;
    Point()
    {
        x=0;
        y=0;
    }


    bool operator==(const Point& p) const
    {
        return x == p.x && y == p.y;
    }
    bool operator<(const Point& p) const
    {
        return x < p.x || (x == p.x && y < p.y);
    }
    bool operator>(const Point& p)const
    {
        return x>p.x || (x==p.x && y>p.y);
    }
};

int orientation(Point a, Point b, Point c)
{

    int result = (b.y - a.y) * (c.x - b.x) - (c.y - b.y) * (b.x - a.x);
    ;
    if (result == 0)
    {
        return 0;
    }
    return (result > 0) ? 1 : -1;
}



int quad(Point p)
{

    if (p.x >= 0 && p.y >= 0)
        return 1;
    if (p.x <= 0 && p.y >= 0)
        return 2;
    if (p.x <= 0 && p.y <= 0)
        return 3;
    return 4;
}

bool compare(Point p1, Point q1)
{
    Point p;

    p.x = p1.x - mid.first,
    p.y = p1.y - mid.second;
    Point q;
    q.x = q1.x - mid.first,
    q.y = q1.y - mid.second;
    int one = quad(p);
    int two = quad(q);

    if (one != two)
        return (one < two);
    return (p.y * q.x < q.y * p.x);
}


void removeDuplicates(vector<Point>& points) {
    sort(points.begin(), points.end());
    points.erase(unique(points.begin(), points.end()), points.end());
}
vector<Point> allPointsOnSameSide(vector<Point>a)
{
    int n = a.size();

    vector<Point> fence;


    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int a1 = a[i].y-a[j].y ;
            int b1 = a[j].x-a[i].x ;
            int c1 = a[i].x * a[j].y-a[i].y * a[j].x ;
            int pos = 0, neg = 0;
            for (int k = 0; k < n; k++)
            {
                int res = a[k].x * a1 + a[k].y * b1 + c1;
                if (res <= 0)
                {
                    neg++;
                }
                if (res >= 0)
                {
                    pos++;
                }
            }
            if (pos == n || neg == n)
            {
                fence.push_back(a[i]);
                fence.push_back(a[j]);

            }
        }
    }
    removeDuplicates(fence);
    return fence;
}




vector<Point> bruteHull(vector<Point> a)
{


    vector<Point> ret;
    ret=allPointsOnSameSide(a);
    mid= {0,0};
    int m = ret.size();
    for (int i = 0; i < m; i++)
    {
        mid.first += ret[i].x;
        mid.second += ret[i].y;
        ret[i].x *= m;
        ret[i].y *= m;
    }
    sort(ret.begin(), ret.end(), compare);
    for (int i=0; i<m; i++)
    {
        ret[i].x = ret[i].x/m;
        ret[i].y= ret[i].y/m;
    }

    return ret;
}

pair<int, int> findLowerTangent(int ia,int ib,const vector<Point>& a, const vector<Point>& b)
{
    int n = a.size();
    int m = b.size();

    int inda = ia, indb = ib;
    bool done = 0;
    while (!done)
    {
        done = 1;
        while (orientation(a[inda], b[indb], b[(indb + 1) % m]) >= 0)
        {
            indb = (indb + 1) % m;
        }
        while (orientation(b[indb], a[inda], a[(n + inda - 1) % n]) <= 0)
        {
            inda = (n + inda - 1) % n;
            done = 0;
        }
    }
    int lowera=inda,lowerb=indb;

    return make_pair(lowera, lowerb);
}

pair<int, int> findUpperTangent(int ia,int ib,const vector<Point>& a, const vector<Point>& b)
{
    int n = a.size();
    int m = b.size();

    int inda = ia, indb = ib;
    bool done = 0;
    while (!done)
    {
        done = 1;
        while (orientation(b[indb], a[inda], a[(inda + 1) % n]) >= 0)
        {
            inda = (inda + 1) % n;
        }
        while (orientation(a[inda], b[indb], b[(m + indb - 1) % m]) <= 0)
        {
            indb = (m + indb - 1) % m;
            done = 0;
        }
    }
    int uppera=inda,upperb=indb;
    return make_pair(uppera, upperb);
}

vector<Point> mergehull(vector<Point> a, vector<Point> b)
{
    int n = a.size();
    int m = b.size();
    int ia=0,ib=0;
    for (int i = 1; i < n; i++)
    {
        if (a[i].x > a[ia].x)
        {
            ia = i;
        }
    }
    for (int i = 1; i < m; i++)
    {
        if (b[i].x < b[ib].x)
        {
            ib = i;
        }
    }

    pair<int, int> lowerTangent = findLowerTangent(ia,ib,a, b);
    pair<int, int> upperTangent = findUpperTangent(ia,ib,a, b);
    vector<Point> ret;
    int ind = upperTangent.first;
    ret.push_back(a[upperTangent.first]);
    while (ind != lowerTangent.first)
    {
        ind = (ind + 1) % n;
        ret.push_back(a[ind]);
    }
    ind = lowerTangent.second;
    ret.push_back(b[lowerTangent.second]);
    while (ind != upperTangent.second)
    {
        ind = (ind + 1) % m;
        ret.push_back(b[ind]);
    }
    return ret;
}

vector<Point> divide(vector<Point>  trees)
{
    if (trees.size() <= 5)
    {
        return bruteHull(trees);
    }

    vector<Point> left, right;
    for (int i = 0; i < trees.size() / 2; i++)
    {
        left.push_back(trees[i]);
    }
    for (int i = trees.size() / 2; i < trees.size(); i++)
    {
        right.push_back(trees[i]);
    }

    vector<Point> left_hull = divide(left);
    vector<Point> right_hull = divide(right);
    return mergehull(left_hull, right_hull);
}

int main()
{


    int N;
    ifstream infile("in.txt");
    ofstream outfile("out.txt");

    infile>>N;
    vector<Point>trees(N);
    for(int i=0; i<N; i++)
    {
        infile>>trees[i].x>>trees[i].y;
    }

    sort(trees.begin(),trees.end(),[](const Point &a,const Point &b)
    {
        return a.x<b.x;
    });

    vector<Point>fence;
    fence=divide(trees);
    for(const Point &p:fence)
    {
        outfile<<p.x<<" "<<p.y<<endl;
    }
    infile.close();
    outfile.close();

    return 0;

}


