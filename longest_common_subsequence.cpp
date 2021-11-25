/// https://infoarena.ro/problema/cmlsc
#include<cstdio>
#include<fstream>
#include<algorithm>
using namespace std;
FILE *f=fopen("cmlsc.in","r");
ofstream g("cmlsc.out");
int a[1030][1030],v[1030],w[1030],s[1030];
int main()
{
    int m,n,i,j,k;
    fscanf(f,"%d%d",&m,&n);
    for(i=1;i<=m;i++)
        fscanf(f,"%d",&v[i]);
    for(i=1;i<=n;i++)
        fscanf(f,"%d",&w[i]);
    for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
        if(v[i]==w[j])
        a[i][j]=a[i-1][j-1]+1;
    else
        a[i][j]=max(a[i-1][j],a[i][j-1]);
    g<<a[m][n]<<'\n';//lungimea celui mai lung subsir
    k=a[m][n];
    i=m;
    j=n;
    while(a[i][j]!=0)
        if(v[i]==w[j])
        {
            s[k]=v[i];
            k--;
            i--;
            j--;
        }
        else
        {
            if(a[i][j]==a[i-1][j])
                i--;
            else
                j--;
        }
    for(i=1;i<=a[m][n];i++)
        g<<s[i]<<" ";
    return 0;
}

