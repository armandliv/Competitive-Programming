/// https://infoarena.ro/problema/cmcm
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 2000000000
using namespace std;
ifstream f("cmcm.in");
ofstream g("cmcm.out");
struct nod
{
    int x,poz;
};
vector<nod>a[604];
nod tata[604];
int N,s,d,flux,sol,r[101205],z[101205],dist[604],dist2[604],realdist[604];
bool inq[604];
queue<int>q;
struct elem
{
    int x,dist;
    inline bool operator < (const elem &a) const
    {
        return dist>a.dist;
    }
};
priority_queue<elem>pq;

inline bool dijkstra()
{
    int i,l,Z;
    elem p;
    for(i=1;i<=N;i++)
        dist[i]=INF,tata[i]={0,0};
    pq.push({s,0});
    dist[s]=0;
    dist2[s]=0;
    while(!pq.empty())
    {
        p=pq.top();
        pq.pop();
        if(p.dist==dist[p.x])
        {
            l=a[p.x].size();
            for(i=0;i<l;i++)
            {
                Z=realdist[p.x]-realdist[a[p.x][i].x]+z[a[p.x][i].poz];
                if(r[a[p.x][i].poz]>0&&dist[a[p.x][i].x]>dist[p.x]+Z)
                {
                    dist[a[p.x][i].x]=dist[p.x]+Z;
                    dist2[a[p.x][i].x]=dist2[p.x]+z[a[p.x][i].poz];
                    tata[a[p.x][i].x].x=p.x;
                    tata[a[p.x][i].x].poz=a[p.x][i].poz;
                    pq.push({a[p.x][i].x,dist[a[p.x][i].x]});
                }
            }
        }
    }
    for(i=1;i<=N;i++)
        realdist[i]=dist2[i];
    return dist[d]!=INF;
}

inline void bellman_ford()
{
    int i,l,p;
    for(i=1;i<=N;i++)
        realdist[i]=INF;
    realdist[s]=0;
    q.push(s);
    inq[s]=1;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        inq[p]=0;
        l=a[p].size();
        for(i=0;i<l;i++)
        if(r[a[p][i].poz]>0&&realdist[a[p][i].x]>realdist[p]+z[a[p][i].poz])
        {
            realdist[a[p][i].x]=realdist[p]+z[a[p][i].poz];
            if(inq[a[p][i].x]==0)
            {
                q.push(a[p][i].x);
                inq[a[p][i].x]=1;
            }
        }
    }
}

inline void fmcm()
{
    int i,flow,cost;
    bellman_ford();
    while(dijkstra()!=0)
    {
        flow=INF;
        for(i=d;i!=s;i=tata[i].x)
        {
            flow=min(flow,r[tata[i].poz]);
            if(flow==0)
                break;
        }
        if(flow!=0&&flow!=INF)
        {
            cost=0;
            for(i=d;i!=s;i=tata[i].x)
            {
                r[tata[i].poz]-=flow;
                r[tata[i].poz^1]+=flow;
                cost+=z[tata[i].poz];
            }
            flux+=flow;
            sol+=flow*cost;
        }
    }
}

int main()
{
    int n,m,i,x,y,zz,k=0,e;
    f>>n>>m>>e;
    for(i=1;i<=e;i++)
    {
        f>>x>>y>>zz;
        y+=n;
        r[k]=1;
        z[k]=zz;
        a[x].push_back({y,k});
        k++;
        r[k]=0;
        z[k]=-zz;
        a[y].push_back({x,k});
        k++;
    }
    s=n+m+1;
    for(i=1;i<=n;i++)
    {
        r[k]=1;
        z[k]=0;
        a[s].push_back({i,k});
        k++;
        r[k]=0;
        z[k]=0;
        a[i].push_back({s,k});
        k++;
    }
    d=n+m+2;
    for(i=n+1;i<=n+m;i++)
    {
        r[k]=1;
        z[k]=0;
        a[i].push_back({d,k});
        k++;
        r[k]=0;
        z[k]=0;
        a[d].push_back({i,k});
        k++;
    }
    N=n+m+2;
    fmcm();
    g<<flux<<" "<<sol<<'\n';
    for(i=1;i<=e;i++)
    if(r[2*(i-1)]==0)
        g<<i<<" ";
    return 0;
}
