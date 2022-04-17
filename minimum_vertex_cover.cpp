/// https://www.infoarena.ro/problema/paznici
#include<fstream>
#include<vector>
using namespace std;
ifstream f("paznici.in");
ofstream g("paznici.out");
vector<int>a[32];
int n,m,st[32],dr[32],sol;
bool tried[32],l[32],r[32],viz[32];
char s[32][32];

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
    int i,j;
    f>>n>>m;
    f.get();
    for(i=1;i<=n;i++)
    {
        f.getline(s[i]+1,28);
        for(j=1;j<=m;j++)
        if(s[i][j]=='1')
            a[i].push_back(j);
    }
    cuplaj();
    ///minimum vertex cover
    for(i=1;i<=n;i++)
    if(st[i]!=0)
        l[i]=1;
    for(i=1;i<=n;i++)
    if(l[i]==0&&viz[i]==0)
        minimum_vertex_cover(i);
    ///e un dfs
    for(i=1;i<=n;i++)
    if(l[i]==1)
        g<<(char)(i+'A'-1);
    for(i=1;i<=n;i++)
    if(r[i]==1)
        g<<(char)(i+'a'-1);
    return 0;
}
