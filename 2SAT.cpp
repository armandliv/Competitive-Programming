/// https://infoarena.ro/problema/2sat
#include<bits/stdc++.h>
using namespace std;
ifstream f("2sat.in");
ofstream g("2sat.out");
vector<int>a[200002],inv[200002];
int n,k,kk[200002],ctc[200002];
bool viz[200002];

int val(int x)
{
    if(x<0)
        return -x+n;
    return x;
}

int neg(int x)
{
    if(x>n)
        return x-n;
    return x+n;
}

void add(int x,int y)
{
    a[x].push_back(y);
    inv[y].push_back(x);
}

void imposibil(int x,int y)
{
    add(x,neg(y));
    add(y,neg(x));
}

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
    ctc[x]=k;
    for(auto y:inv[x])
    if(viz[y]==0)
        dfs_inv(y);
}

void kosaraju()
{
    int i;
    for(i=1;i<=2*n;i++)
    if(viz[i]==0)
        dfs(i);
    for(i=1;i<=2*n;i++)
        viz[i]=0;
    k=0;
    for(i=2*n;i>=1;i--)
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
        x=val(x);
        y=val(y);
        imposibil(neg(x),neg(y));
    }
    kosaraju();
    for(i=1;i<=n;i++)
    if(ctc[i]==ctc[i+n])
    {
        g<<-1;
        return 0;
    }
    for(i=1;i<=n;i++)
    if(ctc[i]<ctc[i+n])
        g<<0<<" ";
    else
        g<<1<<" ";
    return 0;
}
