/// https://infoarena.ro/problema/ctc
#include<fstream>
#include<vector>
using namespace std;
ifstream f("ctc.in");
ofstream g("ctc.out");
vector<int>a[100002],inv[100002],ctc[100002];
int n,k,kk[100002];
bool viz[100002];

void dfs(int x)
{
    viz[x]=1;
    for(auto y:a[x])
    if(viz[y]==0)
        dfs(y);
    kk[++k]=x;
}

void dfs_inv(int x)
{
    viz[x]=1;
    ctc[k].push_back(x);
    for(auto y:inv[x])
    if(viz[y]==0)
        dfs_inv(y);
}

void kosaraju()
{
    int i;
    for(i=1;i<=n;i++)
    if(viz[i]==0)
        dfs(i);
    for(i=1;i<=n;i++)
        viz[i]=0;
    k=0;
    for(i=n;i>=1;i--)
    if(viz[kk[i]]==0)
    {
        k++;
        dfs_inv(kk[i]);
    }
}

int main()
{
    int m,i,x,y;
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y;
        a[x].push_back(y);
        inv[y].push_back(x);
    }
    kosaraju();
    g<<k<<'\n';
    for(i=1;i<=k;i++)
    {
        for(auto z:ctc[i])
            g<<z<<" ";
        g<<'\n';
    }
    return 0;
}
