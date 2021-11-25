/// https://infoarena.ro/problema/royfloyd
#include<fstream>
using namespace std;
ifstream f("royfloyd.in");
ofstream g("royfloyd.out");
int a[102][102];
int main()
{
    int n,i,j,k;
    f>>n;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        f>>a[i][j];
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(a[i][k]!=0&&a[k][j]!=0&&(a[i][k]+a[k][j]<a[i][j]||(a[i][j]==0&&i!=j)))
        a[i][j]=a[i][k]+a[k][j];
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            g<<a[i][j]<<" ";
        g<<'\n';
    }
    return 0;
}
