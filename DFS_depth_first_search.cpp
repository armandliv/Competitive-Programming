/// https://infoarena.ro/problema/dfs
#include<fstream>
#include<vector>
using namespace std;
ifstream f("dfs.in");
ofstream g("dfs.out");
vector<int>a[100002];
bool visited[100002];

void dfs(int x)
{
    int i;
    visited[x]=1;
    for(i=0;i<a[x].size();i++)
    if(visited[a[x][i]]==0)
    {
        dfs(a[x][i]);
    }
}

int main()
{
    int n,m,i,x,y,k=0;
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(i=1;i<=n;i++)
    if(visited[i]==0)
    {
        dfs(i);
        k++;
    }
    g<<k;
    return 0;
}
