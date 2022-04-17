/// https://www.infoarena.ro/problema/edist
#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("edist.in");
ofstream g("edist.out");
char s1[20002],s2[20002];
int dp[2][20002];
int main()
{
    int n,m,k,i,j,st,dr;
    f>>n>>m>>k;
    f.get();
    f.getline(s1+1,20001);
    f.getline(s2+1,20001);
    for(i=1;i<=m;i++)
        dp[0][i]=i;
    for(i=1;i<=n;i++)
    {
        dp[i%2][0]=i;
        st=max(0,i-k);
        dr=min(m,i+k);
        for(j=st;j<=dr;j++)
        {
            dp[i%2][j]=max(i,j);
            dp[i%2][j]=min(dp[i%2][j],dp[(i-1)%2][j]+1);
            dp[i%2][j]=min(dp[i%2][j],dp[i%2][j-1]+1);
            dp[i%2][j]=min(dp[i%2][j],dp[(i-1)%2][j-1]+(s1[i]!=s2[j]));
        }
    }
    g<<dp[n%2][m];
    return 0;
}
