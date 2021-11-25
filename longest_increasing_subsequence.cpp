/// https://infoarena.ro/problema/scmax
#include<fstream>
using namespace std;
ifstream f("scmax.in");
ofstream g("scmax.out");
int v[100002],t[100002],r[100002];

void reconstituire(int x)
{
    if(x!=0)
    {
        reconstituire(r[x]);
        g<<v[x]<<" ";
    }
}

int main()
{
    int n,i,l=0,st,dr,mij,p;
    f>>n;
    for(i=1;i<=n;i++)
        f>>v[i];
    for(i=1;i<=n;i++)
    {
        st=1;
        dr=l;
        while(st<=dr)
        {
            mij=(st+dr)/2;
            if(v[t[mij]]<v[i])
                st=mij+1;
            else
                dr=mij-1;
        }
        p=st-1;
        p++;
        if(p>l)
            l=p;
        t[p]=i;
        r[i]=t[p-1];
    }
    g<<l<<'\n';
    reconstituire(t[l]);
    return 0;
}
