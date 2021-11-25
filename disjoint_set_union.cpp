/// https://infoarena.ro/problema/disjoint
#include<fstream>
using namespace std;
ifstream f("disjoint.in");
ofstream g("disjoint.out");
int tata[100002],dim[100002];

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
    int n,m,p,x,y,i;
    f>>n>>m;
    for(i=1;i<=n;i++)
        tata[i]=i,dim[i]=1;
    for(i=1;i<=m;i++)
    {
        f>>p>>x>>y;
        if(p==1)
            unire(x,y);
        else
        {
            if(tata_multime(x)==tata_multime(y))
                g<<"DA"<<'\n';
            else
                g<<"NU"<<'\n';
        }
    }
    return 0;
}
