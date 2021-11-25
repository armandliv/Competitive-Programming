/// https://infoarena.ro/problema/cuplaj
#include<fstream>
#include<vector>
using namespace std;
ifstream f("cuplaj.in");
ofstream g("cuplaj.out");
vector<int>a[10002];
int n,m,st[10002],dr[10002],sol;
bool tried[10002];

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

int main()
{
    int e,i,x,y;
    f>>n>>m>>e;
    for(i=1;i<=e;i++)
    {
        f>>x>>y;
        a[x].push_back(y);
    }
    cuplaj();
    g<<sol<<'\n';
    for(i=1;i<=n;i++)
    if(st[i]!=0)
        g<<i<<" "<<st[i]<<'\n';
    return 0;
}
