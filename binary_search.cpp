/// https://infoarena.ro/problema/cautbin
#include<fstream>
#include<cstdio>
using namespace std;
FILE *f=fopen("cautbin.in","r");
ofstream g("cautbin.out");
int v[100002],n;

int cautbin_0(int x)
{
    int st=1,dr=n,mij;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(x<v[mij])
            dr=mij-1;
        else
        if(x>=v[mij])
            st=mij+1;
    }
    mij=(st+dr)/2;
    if(v[mij]==x)
        return mij;
    return -1;
}

int cautbin_1(int x)
{
    int st=1,dr=n,mij;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(x<v[mij])
            dr=mij-1;
        else
        if(x>=v[mij])
            st=mij+1;
    }
    return st-1;
}

int cautbin_2(int x)
{
    int st=1,dr=n,mij;
    while(st<=dr)
    {
        mij=(st+dr)/2;
        if(x<=v[mij])
            dr=mij-1;
        else
        if(x>v[mij])
            st=mij+1;
        else
            return mij;
    }
    return dr+1;
}

int main()
{
    int i,m,p,x;
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
        fscanf(f,"%d",&v[i]);
    fscanf(f,"%d",&m);
    for(i=1;i<=m;i++)
    {
        fscanf(f,"%d%d",&p,&x);
        if(p==0)
            g<<cautbin_0(x);
        else
        if(p==1)
            g<<cautbin_1(x);
        else
        if(p==2)
            g<<cautbin_2(x);
        g<<'\n';
    }
    return 0;
}
