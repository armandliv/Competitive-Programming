/// https://infoarena.ro/problema/bellmanford
#include<fstream>
#include<vector>
#include<queue>
#define INF 2000000000
using namespace std;
ifstream f("bellmanford.in");
ofstream g("bellmanford.out");
struct elem
{
    int x,c;
};
vector<elem>a[50002];
queue<int>q;
int dist[50002],nr[50002];
bool inq[50002];
int main()
{
    int n,m,i,x,y,z,p,ok=1,l;
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y>>z;
        a[x].push_back({y,z});
    }
    for(i=1;i<=n;i++)
        dist[i]=INF;
    dist[1]=0;
    q.push(1);
    inq[1]=1;
    nr[1]=1;
    while(!q.empty()&&ok==1)
    {
        p=q.front();
        q.pop();
        inq[p]=0;
        l=a[p].size();
        for(i=0;i<l;i++)
        if(dist[a[p][i].x]>dist[p]+a[p][i].c)
        {
            dist[a[p][i].x]=dist[p]+a[p][i].c;
            if(inq[a[p][i].x]==0)
            {
                q.push(a[p][i].x);
                inq[a[p][i].x]=1;
                nr[a[p][i].x]++;
                if(nr[a[p][i].x]==n)
                {
                    ok=0;
                    break;
                }
            }
        }
    }
    if(ok==0)
        g<<"Ciclu negativ!";
    else
    {
        for(i=2;i<=n;i++)
            g<<dist[i]<<" ";
    }
    return 0;
}
