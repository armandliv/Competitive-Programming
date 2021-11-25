/// https://infoarena.ro/problema/ssm
#include<cstdio>
#include<fstream>
#include<climits>
using namespace std;
FILE *f=fopen("ssm.in","r");
ofstream g("ssm.out");

int main()
{
    int n,i,s=0,smin=0,x,st,dr,smax=INT_MIN,j=1;
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d",&x);
        s+=x;
        if(s-smin>smax)
            smax=s-smin,dr=i,st=j;
        if(s<smin)
            smin=s,j=i+1;
    }
    g<<smax<<" "<<st<<" "<<dr;
    return 0;
}

