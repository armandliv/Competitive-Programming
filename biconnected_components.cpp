/// https://infoarena.ro/problema/biconex
#include<fstream>
#include<algorithm>
#include<vector>
using namespace std;
ifstream f("biconex.in");
ofstream g("biconex.out");
vector<int>a[100002],sol[100002];
int niv[100002],low[100002],st[100002],vf,k;

void dfs_tree(int x)
{
    st[++vf]=x;
    low[x]=niv[x];
    for(auto y:a[x])
    if(niv[y]!=0)
        low[x]=min(low[x],niv[y]);
    else
    {
        niv[y]=niv[x]+1;
        dfs_tree(y);
        low[x]=min(low[x],low[y]);
        if(low[y]>=niv[x])
        {
            k++;
            while(st[vf]!=y)
                sol[k].push_back(st[vf--]);
            sol[k].push_back(st[vf--]);
            sol[k].push_back(x);
        }
    }
}

int main()
{
    int n,m,i,x,y;
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(i=1;i<=n;i++)
    if(niv[i]==0)
    {
        niv[i]=1;
        dfs_tree(i);
    }
    g<<k<<'\n';
    for(i=1;i<=k;i++)
    {
        for(auto z:sol[i])
            g<<z<<" ";
        g<<'\n';
    }
    return 0;
}
