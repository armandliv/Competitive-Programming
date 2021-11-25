/// https://infoarena.ro/problema/infasuratoare
#include<fstream>
#include<algorithm>
#include<iomanip>
using namespace std;
ifstream f("infasuratoare.in");
ofstream g("infasuratoare.out");
int st[120002];
bool viz[120002];

struct punct
{
    long double x,y;
};
punct v[120002];

inline bool cmp(const punct &a,const punct &b)
{
    if(a.x==b.x)
        return a.y<b.y;
    return a.x<b.x;
}

inline bool calc(punct a,punct b,punct c)
{
    return (c.y-a.y)*(b.x-a.x)<=(b.y-a.y)*(c.x-a.x);
}

int main()
{
    int n,i,vf,pas;
    f>>n;
    for(i=1;i<=n;i++)
        f>>v[i].x>>v[i].y;
    sort(v+1,v+n+1,cmp);
    st[1]=1;
    st[2]=2;
    vf=2;
    viz[2]=1;
    i=3;
    pas=1;
    while(viz[1]==0)
    {
        if(viz[i]==0)
        {
            while(vf>1&&calc(v[st[vf-1]],v[st[vf]],v[i])==1)
                viz[st[vf]]=0,vf--;
            st[++vf]=i;
            viz[i]=1;
        }
        if(i==n)
            pas=-1;
        i+=pas;
    }
    vf--;
    g<<vf<<'\n';
    for(i=1;i<=vf;i++)
        g<<fixed<<setprecision(12)<<v[st[i]].x<<" "<<fixed<<setprecision(12)<<v[st[i]].y<<'\n';
    return 0;
}
