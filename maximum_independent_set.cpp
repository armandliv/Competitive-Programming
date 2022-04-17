/// https://www.infoarena.ro/problema/felinare
#include<fstream>
#include<vector>
using namespace std;
ifstream f("felinare.in");
ofstream g("felinare.out");
vector<int>a[8192];
int n,m,st[8192],dr[8192],sol;
bool tried[8192],l[8192],r[8192],viz[8192];

bool cupleaza(int x)
{
    if(tried[x]==1)
        return 0;
    tried[x]=1;
    for(auto y:a[x])
    if(dr[y]==0)
    {
        sol++;
        st[x]=y;
        dr[y]=x;
        return 1;
    }
    for(auto y:a[x])
    if(cupleaza(dr[y])==1)
    {
        st[x]=y;
        dr[y]=x;
        return 1;
    }
    return 0;
}

void cuplaj()
{
    int i;
    bool ok=1;
    while(ok==1)
    {
        for(i=1;i<=n;i++)
            tried[i]=0;
        ok=0;
        for(i=1;i<=n;i++)
        if(st[i]==0)
            ok|=cupleaza(i);
    }
}

void minimum_vertex_cover(int x)
{
    viz[x]=1;
    l[x]=0;
    for(auto y:a[x])
    if(viz[dr[y]]==0)
    {
        r[y]=1;
        minimum_vertex_cover(dr[y]);
    }
}

int main()
{
    int i,x,y;
    f>>n>>m;
    f.get();
    for(i=1;i<=m;i++)
    {
        f>>x>>y;
        a[x].push_back(y);
    }
    cuplaj();
    ///minimum vertex cover
    for(i=1;i<=n;i++)
    if(st[i]!=0)
        l[i]=1;
    for(i=1;i<=n;i++)
    if(l[i]==0&&viz[i]==0)
        minimum_vertex_cover(i);
    ///felinare aprinse -> nodurile din maximum independent set (=cele care nu sunt in minimum vertex cover)
    g<<2*n-sol<<'\n';
    for(i=1;i<=n;i++)
    {
        if(l[i]==1&&r[i]==1)
            g<<0;
        else
        if(l[i]==0&&r[i]==1)
            g<<1;
        else
        if(l[i]==1&&r[i]==0)
            g<<2;
        else
        if(l[i]==0&&r[i]==0)
            g<<3;
        g<<'\n';
    }
    return 0;
}
