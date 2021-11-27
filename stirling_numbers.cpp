/// https://infoarena.ro/problema/stirling
#include<fstream>
#define MOD 98999
using namespace std;
ifstream f("stirling.in");
ofstream g("stirling.out");
int s[202][202],S[202][202];
int main()
{
    int t,p,n,m,i,j;
    s[0][0]=1;
    S[0][0]=1;
    for(i=1;i<=200;i++)
    for(j=1;j<=i;j++)
    {
        s[i][j]=s[i-1][j]*(1-i)+s[i-1][j-1];
        s[i][j]%=MOD;
        S[i][j]=S[i-1][j]*j+S[i-1][j-1];
        S[i][j]%=MOD;
    }
    f>>t;
    for(i=1;i<=t;i++)
    {
        f>>p>>n>>m;
        if(p==1)
            g<<s[n][m];
        else
            g<<S[n][m];
        g<<'\n';
    }
    return 0;
}
