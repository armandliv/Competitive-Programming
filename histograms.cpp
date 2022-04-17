/// https://www.infoarena.ro/problema/matrix2
#include<cstdio>
#include<fstream>
using namespace std;
FILE *f=fopen("matrix2.in","r");
ofstream g("matrix2.out");
int a[1002][1002],h[1002][1002],st[1002];
int main()
{
    int n,m,i,j,sol=0,area;
    fscanf(f,"%d%d",&n,&m);
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        fscanf(f,"%d",&a[i][j]);
        if(a[i][j]==0)
            h[i][j]=h[i][j-1]+1;
    }
    for(j=1;j<=m;j++)
    {
        int v=1;
        st[v]=0;
        for(i=1;i<=n+1;i++)
        {
            while(h[i][j]<=h[st[v]][j]&&v>=1)
            {
                area=h[st[v]][j]*(i-1-st[v-1]);
                if(area>sol)
                    sol=area;
                v--;
            }
            st[++v]=i;
        }
    }
    g<<sol;
    return 0;
}
