/// https://infoarena.ro/problema/gauss
#include<bits/stdc++.h>
#define eps 0.0000000001
using namespace std;
ifstream f("gauss.in");
ofstream g("gauss.out");
long double a[302][302],v[302];

bool zero(long double x)
{
    if(x<eps&&x>-eps)
        return 1;
    return 0;
}

int main()
{
    int n,m,i,j,x,y,ok=1;
    f>>n>>m;
    for(i=1;i<=n;i++)
    for(j=1;j<=m+1;j++)
        f>>a[i][j];
    x=1;
    y=1;
    while(x<=n&&y<=m)
    {
        for(i=x;i<=n;i++)
        if(!zero(a[i][y]))
            break;
        if(i!=n+1)
        {
            if(i!=x)
                swap(a[x],a[i]);
            for(j=y+1;j<=m+1;j++)
                a[x][j]/=a[x][y];
            a[x][y]=1;
            for(i=x+1;i<=n;i++)
            {
                for(j=y+1;j<=m+1;j++)
                    a[i][j]-=a[x][j]*a[i][y];
                a[i][y]=0;
            }
            x++;
        }
        y++;
    }
    for(x=n;x>=1;x--)
    {
        for(y=1;y<=m+1;y++)
        if(!zero(a[x][y]))
            break;
        if(y==m+1)
        {
            ok=0;
            break;
        }
        else
        {
            v[y]=a[x][m+1];
            for(j=y+1;j<=m;j++)
                v[y]-=a[x][j]*v[j];
        }
    }
    if(ok==0)
        g<<"Imposibil";
    else
    {
        for(i=1;i<=m;i++)
            g<<fixed<<setprecision(10)<<v[i]<<" ";
    }
    return 0;
}
