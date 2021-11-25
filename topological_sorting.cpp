/// https://infoarena.ro/problema/sortaret
#include<fstream>
#include<vector>
using namespace std;
ifstream f("sortaret.in");
ofstream g("sortaret.out");
vector<int>a[50002];
int viz[50002],sol[50002],k;

void dfs(int x)
{
    int i,l=a[x].size();
    viz[x]=1;
    for(i=0;i<l;i++)
    if(viz[a[x][i]]==0)
        dfs(a[x][i]);
    sol[++k]=x;
}

int main()
{
    int n,m,i,x,y;
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y;
        a[x].push_back(y);
    }
    for(i=1;i<=n;i++)
    if(viz[i]==0)
        dfs(i);
    for(i=k;i>=1;i--)
        g<<sol[i]<<" ";
    return 0;
}
