/// https://infoarena.ro/problema/dijkstra
#include<fstream>
#include<vector>
#include<queue>
#define INF 2000000000
using namespace std;
ifstream f("dijkstra.in");
ofstream g("dijkstra.out");
struct elem
{
    int x,c;
    bool operator < (const elem &a) const
    {
        return c>a.c;
    }
};
vector<elem>a[50002];
priority_queue<elem>pq;
int sol[50002];
int main()
{
    int n,m,i,x,y,z,l;
    elem p;
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y>>z;
        a[x].push_back({y,z});
        a[y].push_back({y,z});
    }
    for(i=2;i<=n;i++)
        sol[i]=INF;
    pq.push({1,0});
    while(!pq.empty())
    {
        p=pq.top();
        pq.pop();
        if(p.c==sol[p.x])
        {
            l=a[p.x].size();
            for(i=0;i<l;i++)
            if(sol[a[p.x][i].x]>sol[p.x]+a[p.x][i].c)
            {
                sol[a[p.x][i].x]=sol[p.x]+a[p.x][i].c;
                pq.push({a[p.x][i].x,sol[a[p.x][i].x]});
            }
        }
    }
    for(i=2;i<=n;i++)
    if(sol[i]==INF)
        g<<0<<" ";
    else
        g<<sol[i]<<" ";
    return 0;
}
