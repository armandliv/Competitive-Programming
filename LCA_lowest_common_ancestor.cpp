/// https://infoarena.ro/problema/lca
#include<cstdio>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
FILE *f=fopen("lca.in","r");
ofstream g("lca.out");
vector<int>a[100002];
struct elem
{
    int x,niv;
};
elem v[200002],rmq[200002][20];
int k,t[100002],nivel[100002],puteri[200002],e[200002],ap[100002];

void dfs(int x)
{
    int n=a[x].size(),i;
    nivel[x]=nivel[t[x]]+1;
    v[++k].x=x;
    v[k].niv=nivel[x];
    for(i=0;i<n;i++)
    {
        dfs(a[x][i]);
        v[++k].x=x;
        v[k].niv=nivel[x];
    }
}

void rmqlca()
{
    int i,p,q=1;
    for(i=1;i<=k;i++)
        rmq[i][0]=v[i];
    for(p=1;p*2<=k;p*=2)
    {
        for(i=1;i<=k-p*2+1;i++)
        if(rmq[i][q-1].niv<rmq[i+p][q-1].niv)
            rmq[i][q]=rmq[i][q-1];
        else
            rmq[i][q]=rmq[i+p][q-1];
        q++;
    }
    p=1;
    q=0;
    for(i=1;i<=k;i++)
    {
        if(p*2<=i)
            p*=2,q++;
        puteri[i]=p;
        e[i]=q;
    }
}

int lca(int x,int y)
{
    int l;
    x=ap[x];
    y=ap[y];
    if(x>y)
        swap(x,y);
    l=y-x+1;
    if(rmq[x][e[l]].niv<rmq[y-puteri[l]+1][e[l]].niv)
        return rmq[x][e[l]].x;
    else
        return rmq[y-puteri[l]+1][e[l]].x;
}

int main()
{
    int n,m,x,i,y;
    fscanf(f,"%d%d",&n,&m);
    for(i=2;i<=n;i++)
    {
        fscanf(f,"%d",&t[i]);
        a[t[i]].push_back(i);
    }
    dfs(1);
    rmqlca();
    for(i=1;i<=k;i++)
    if(ap[v[i].x]==0)
        ap[v[i].x]=i;
    for(i=1;i<=m;i++)
    {
        fscanf(f,"%d%d",&x,&y);
        g<<lca(x,y)<<'\n';
    }
    return 0;
}
