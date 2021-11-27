/// https://infoarena.ro/problema/cmap
#include<fstream>
#include<cmath>
#include<algorithm>
#include<iomanip>
#define INF 1000000000000000000
using namespace std;
ifstream f("cmap.in");
ofstream g("cmap.out");

struct punct
{
    int x,y;
};
punct v[100002],w[100002];

inline bool cmp(const punct &a,const punct &b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

long long dist(punct a,punct b)
{
    return (long long)(a.x-b.x)*(a.x-b.x)+(long long)(a.y-b.y)*(a.y-b.y);
}

void interclasare(int st,int dr)
{
    int i,j,mij=(st+dr)/2,k=0;
    i=st;
    j=mij+1;
    while(i<=mij&&j<=dr)
    {
        if(v[i].y<v[j].y)
            w[++k]=v[i++];
        else
            w[++k]=v[j++];
    }
    while(i<=mij)
        w[++k]=v[i++];
    while(j<=dr)
        w[++k]=v[j++];
    for(i=st;i<=dr;i++)
        v[i]=w[i-st+1];
}

long long divide_et_impera(int st,int dr)
{
    if(st>=dr)
        return INF;
    int i,j,mij=(st+dr)/2,k=0,x;
    long long d;
    x=v[mij].x;
    d=min(divide_et_impera(st,mij),divide_et_impera(mij+1,dr));
    interclasare(st,dr);
    for(i=st;i<=dr;i++)
    if((long long)(v[i].x-x)*(v[i].x-x)<d)
        w[++k]=v[i];
    for(i=1;i<k;i++)
    for(j=i+1;j<=i+5&&j<=k;j++)
        d=min(d,dist(w[i],w[j]));
    return d;
}

int main()
{
    int n,i;
    long long sol;
    f>>n;
    for(i=1;i<=n;i++)
        f>>v[i].x>>v[i].y;
    sort(v+1,v+n+1,cmp);
    sol=divide_et_impera(1,n);
    g<<fixed<<setprecision(6)<<(long double)sqrtl(sol);
    return 0;
}
