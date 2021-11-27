/// https://infoarena.ro/problema/submultimi
#include<cstdio>
#include<fstream>
using namespace std;
FILE *f=fopen("submultimi.in","r");
ofstream g("submultimi.out");
int v[20];
int main()
{
    int n,i,ok=0;
    fscanf(f,"%d",&n);
    v[1]=1;
    while(ok==0)
    {
        for(i=1;i<=n;i++)
        if(v[i]==1)
            g<<i<<" ";
        g<<'\n';
        v[1]++;
        for(i=1;i<=n;i++)
        if(v[i]>1)
        {
            v[i]=0;
            v[i+1]++;
        }
        ok=1;
        if(v[n+1]!=1)
            ok=0;
    }
    return 0;
}
