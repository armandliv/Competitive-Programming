/// https://infoarena.ro/problema/maxflow
#include<fstream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
ifstream f("maxflow.in");
ofstream g("maxflow.out");
struct elem
{
    int x,poz;
};
vector<elem>a[1002];
elem tata[1002];
int n,s,d,sol,r[10002];
bool viz[1002];
queue<int>q;

inline bool bfs()
{
    int i,x,l;
    for(i=1;i<=n;i++)
        viz[i]=0,tata[i]={0,0};
    q.push(s);
    viz[s]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        l=a[x].size();
        for(i=0;i<l;i++)
        if(viz[a[x][i].x]==0&&r[a[x][i].poz]>0)
        {
            viz[a[x][i].x]=1;
            tata[a[x][i].x].x=x;
            tata[a[x][i].x].poz=a[x][i].poz;
            q.push(a[x][i].x);
        }
    }
    return viz[d];
}

inline void flux_maxim()
{
    int i,j,flow,l=a[d].size();
    while(bfs()!=0)
    {
        for(i=0;i<l;i++)
        if((tata[a[d][i].x].x!=0||a[d][i].x==s)&&r[a[d][i].poz^1]>0)
        {
            flow=r[a[d][i].poz^1];
            for(j=a[d][i].x;j!=s;j=tata[j].x)
            {
                flow=min(flow,r[tata[j].poz]);
                if(flow==0)
                    break;
            }
            if(flow!=0)
            {
                r[a[d][i].poz^1]-=flow;
                r[a[d][i].poz]+=flow;
                for(j=a[d][i].x;j!=s;j=tata[j].x)
                {
                    r[tata[j].poz]-=flow;
                    r[tata[j].poz^1]+=flow;
                }
                sol+=flow;
            }
        }
    }
}

int main()
{
    int m,i,x,y,c,k=0;
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y>>c;
        r[k]=c;
        a[x].push_back({y,k});
        k++;
        r[k]=0;
        a[y].push_back({x,k});
        k++;
    }
    s=1;
    d=n;
    flux_maxim();
    g<<sol;
    return 0;
}
