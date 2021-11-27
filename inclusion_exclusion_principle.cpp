/// https://infoarena.ro/problema/pinex
#include<fstream>
#include<cmath>
using namespace std;
ifstream f("pinex.in");
ofstream g("pinex.out");
bool w[1000002];
long long v[100002],l,p[20],q[20];

void ciur()
{
    int i,j;
    w[0]=w[1]=1;
    for(i=4;i<=1000000;i+=2)
        w[i]=1;
    for(i=3;i*i<=1000000;i+=2)
    if(w[i]==0)
    for(j=i*i;j<=1000000;j+=i)
        w[j]=1;
    v[++l]=2;
    for(i=3;i<=1000000;i+=2)
    if(w[i]==0)
        v[++l]=i;
}

int main()
{
    long long n,a,b,sol,r,j,k,x,y,i;
    f>>n;
    ciur();
    for(j=1;j<=n;j++)
    {
        f>>a>>b;
        sol=0;
        r=sqrtl(b);
        i=1;
        k=0;
        while(i<=l&&v[i]<=r&&b!=1)
        {
            if(b%v[i]==0)
            {
                p[++k]=v[i];
                while(b%v[i]==0)
                    b/=v[i];
            }
            i++;
        }
        if(b!=1)
            p[++k]=b;
        for(i=0;i<=k;i++)
            q[i]=0;
        while(q[0]==0)
        {
            x=1;
            y=0;
            for(i=1;i<=k;i++)
            if(q[i]==1)
            {
                x*=p[i];
                y++;
            }
            if(y%2==0)
                sol+=a/x;
            else
                sol-=a/x;
            q[k]++;
            i=k;
            while(q[i]==2)
                q[i]=0,q[--i]++;
        }
        g<<sol<<'\n';
    }
    return 0;
}
