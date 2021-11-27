/// https://infoarena.ro/problema/rucsac
#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("rucsac.in");
ofstream g("rucsac.out");
struct elem
{
    int w,p;
};
elem v[5002];
int dp[2][10002];
int main()
{
    int n,G,i,j,sol=0;
    f>>n>>G;
    for(i=1;i<=n;i++)
        f>>v[i].w>>v[i].p;
    for(i=1;i<=n;i++)
    {
        for(j=G;j>=0;j--)
        {
            dp[i%2][j]=dp[(i-1)%2][j];
            if(j+v[i].w<=G)
                dp[i%2][j+v[i].w]=max(dp[i%2][j+v[i].w],dp[(i-1)%2][j]+v[i].p);
        }
    }
    for(i=1;i<=G;i++)
        sol=max(sol,dp[n%2][i]);
    g<<sol;
    return 0;
}
