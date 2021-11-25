/// https://infoarena.ro/problema/hamilton
#include<fstream>
#include<vector>
#include<algorithm>
#define INF 2000000000
using namespace std;
ifstream f("hamilton.in");
ofstream g("hamilton.out");
struct elem
{
    int x,c;
};
vector<elem>a[20];
int dp[262150][20];
int main()
{
    int n,m,i,x,y,z,p=1,j,sol=INF,l,k;
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y>>z;
        a[x].push_back({y,z});
    }
    for(i=1;i<=n;i++)
        p*=2;
    p--;
    for(i=0;i<=p;i++)
    for(j=0;j<n;j++)
        dp[i][j]=INF;
    dp[1][0]=0;
    for(i=0;i<p;i++)
    for(j=0;j<n;j++)
    if(dp[i][j]!=INF)
    {
        l=a[j].size();
        for(k=0;k<l;k++)
        if((i&(1<<a[j][k].x))==0)
            dp[i|(1<<a[j][k].x)][a[j][k].x]=min(dp[i|(1<<a[j][k].x)][a[j][k].x],dp[i][j]+a[j][k].c);
    }
    for(i=0;i<n;i++)
    if(dp[p][i]!=INF)
    {
        l=a[i].size();
        for(j=0;j<l;j++)
        if(a[i][j].x==0)
            sol=min(sol,dp[p][i]+a[i][j].c);
    }
    if(sol==INF)
        g<<"Nu exista solutie";
    else
        g<<sol;
    return 0;
}
