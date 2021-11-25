/// https://infoarena.ro/problema/hashuri
#include<cstdio>
#include<fstream>
#include<vector>
using namespace std;
FILE *f=fopen("hashuri.in","r");
ofstream g("hashuri.out");
#define MOD 666013
vector<int> v[666015];

void adauga(int x)
{
    int y,i,n,ok=0;
    y=x%MOD;
    n=v[y].size();
    for(i=0;i<n;i++)
    if(v[y][i]==x)
    {
        ok=1;
        break;
    }
    if(ok==0)
        v[y].push_back(x);
}

void sterge(int x)
{
    int y,i,n;
    y=x%MOD;
    n=v[y].size();
    for(i=0;i<n;i++)
    if(v[y][i]==x)
    {
        v[y].erase(v[y].begin()+i);
        break;
    }
}

void cauta(int x)
{
    int y,i,n,ok=0;
    y=x%MOD;
    n=v[y].size();
    for(i=0;i<n;i++)
    if(v[y][i]==x)
    {
        ok=1;
        break;
    }
    g<<ok<<'\n';
}

int main()
{
    int i,n,p,x;
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d%d",&p,&x);
        if(p==1)
            adauga(x);
        else
        if(p==2)
            sterge(x);
        else
            cauta(x);
    }
    return 0;
}
