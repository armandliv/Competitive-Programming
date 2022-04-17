/// https://www.infoarena.ro/problema/biscuiti
#include<fstream>
#define INF 1000000000000000000
using namespace std;
ifstream f("biscuiti.in");
ofstream g("biscuiti.out");
long long n,lazy[400002];
struct elem
{
    long long minim,poz;
};
elem aint[400002];

void propagate(long long nod,long long st,long long dr)
{
    aint[nod].minim+=lazy[nod];
    if(st!=dr)
    {
        lazy[2*nod]+=lazy[nod];
        lazy[2*nod+1]+=lazy[nod];
    }
    lazy[nod]=0;
}

elem join(long long x,long long y)
{
    elem z;
    if(aint[x].minim+lazy[x]<=aint[y].minim+lazy[y])
        z.minim=aint[x].minim+lazy[x],z.poz=aint[x].poz;
    else
        z.minim=aint[y].minim+lazy[y],z.poz=aint[y].poz;
    return z;
}

void update(long long nod,long long st,long long dr,long long index,long long value)
{
    propagate(nod,st,dr);
    if(st==dr)
        aint[nod].minim=value,aint[nod].poz=st;
    else
    {
        long long mij=(st+dr)/2;
        if(index<=mij)
            update(2*nod,st,mij,index,value);
        else
            update(2*nod+1,mij+1,dr,index,value);
        aint[nod]=join(2*nod,2*nod+1);
    }
}

void update(long long a,long long b)
{
    update(1,1,n,a,b);
}

void lazy_update(long long nod,long long st,long long dr,long long left,long long right,long long value)
{
    if(st==left&&dr==right)
    {
        lazy[nod]+=value;
        propagate(nod,st,dr);
    }
    else
    {
        long long mij=(st+dr)/2;
        if(right<=mij)
            return lazy_update(2*nod,st,mij,left,right,value);
        else
        if(mij<left)
            return lazy_update(2*nod+1,mij+1,dr,left,right,value);
        else
        {
            lazy_update(2*nod,st,mij,left,mij,value);
            lazy_update(2*nod+1,mij+1,dr,mij+1,right,value);
        }
    }
}

void lazy_update(long long a,long long b,long long value)
{
    lazy_update(1,1,n,a,b,value);
}

int main()
{
    long long i,sol=0,x;
    f>>n;
    for(i=1;i<=n;i++)
        f>>x,update(i,x),sol-=x;
    for(i=1;i<=n;i++)
    {
        sol+=aint[1].minim+lazy[1];
        lazy_update(1,aint[1].poz,i);
        update(aint[1].poz,INF);
    }
    g<<sol;
    return 0;
}
