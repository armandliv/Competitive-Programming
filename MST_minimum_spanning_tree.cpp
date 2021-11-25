/// https://infoarena.ro/problema/apm
#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("apm.in");
ofstream g("apm.out");
struct elem
{
    int x,y,c;
};
elem v[400002],sol[200002];

inline bool cmp(const elem &a,const elem &b)
{
    return a.c<b.c;
}
int tata[200002],dim[200002];

int tata_multime(int x)
{
    if(x!=tata[x])
        tata[x]=tata_multime(tata[x]);
    return tata[x];
}

void unire(int x,int y)
{
    x=tata_multime(x);
    y=tata_multime(y);
    if(dim[x]<dim[y])
    {
        dim[y]+=dim[x];
        tata[x]=y;
    }
    else
    {
        dim[x]+=dim[y];
        tata[y]=x;
    }
}

int main()
{
    int n,m,i,k=0,s=0;
    f>>n>>m;
    for(i=1;i<=m;i++)
        f>>v[i].x>>v[i].y>>v[i].c;
    sort(v+1,v+m+1,cmp);
    for(i=1;i<=n;i++)
        tata[i]=i,dim[i]=1;
    for(i=1;i<=m&&k<n-1;i++)
    {
        if(tata_multime(v[i].x)!=tata_multime(v[i].y))
        {
            unire(v[i].x,v[i].y);
            s+=v[i].c;
            sol[++k]=v[i];
        }
    }
    g<<s<<'\n'<<n-1<<'\n';
    for(i=1;i<=k;i++)
        g<<sol[i].x<<" "<<sol[i].y<<'\n';
    return 0;
}
