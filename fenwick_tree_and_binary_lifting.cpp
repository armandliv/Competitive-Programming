/// https://infoarena.ro/problema/aib
#include<fstream>
using namespace std;
ifstream f("aib.in");
ofstream g("aib.out");
int n,aib[100002],pw;

void update(int poz,int add)
{
    int i;
    for(i=poz;i<=n;i+=i&-i)
        aib[i]+=add;
}

int querysum(int poz)
{
    int sol=0,i;
    for(i=poz;i>=1;i-=i&-i)
        sol+=aib[i];
    return sol;
}

int rez(int s)
{
    int p=pw,i=0,ok=0;
    while(p>=1)
    {
        if(aib[i+p]==s)
            ok=1;
        if(aib[i+p]<s)
        {
            s-=aib[i+p];
            i+=p;
        }
        p/=2;
        while(p>=1&&i+p>n)
            p/=2;
    }
    if(ok==1)
        return i+1;
    else
        return -1;
}

int main()
{
    int m,i,p,a,b,x;
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>x;
        update(i,x);
    }
    pw=1;
    while(pw<=n)
        pw*=2;
    pw/=2;
    for(i=1;i<=m;i++)
    {
        f>>p;
        if(p==0)
        {
            f>>a>>b;
            update(a,b);
        }
        else
        if(p==1)
        {
            f>>a>>b;
            g<<querysum(b)-querysum(a-1)<<'\n';
        }
        else
        {
            f>>a;
            g<<rez(a)<<'\n';
        }
    }
    return 0;
}
