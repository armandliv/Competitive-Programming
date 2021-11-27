/// https://infoarena.ro/problema/darb
#include<cstdio>
#include<fstream>
#include<vector>
using namespace std;
FILE *f=fopen("darb.in","r");
ofstream g("darb.out");
int v[100002],maxim,p;
vector<int>a[100002];

void dfs(int nod,int tata)
{
    int i,n=a[nod].size();
    if(v[nod]>maxim)
    {
        maxim=v[nod];
        p=nod;
    }
    for(i=0;i<n;i++)
    if(a[nod][i]!=tata)
    {
        v[a[nod][i]]=v[nod]+1;
        dfs(a[nod][i],nod);
    }
}

int main()
{
    int n,i,x,y;
    fscanf(f,"%d",&n);
    for(i=1;i<=n-1;i++)
    {
        fscanf(f,"%d%d",&x,&y);
        a[x].push_back(y);
        a[y].push_back(x);
    }
    v[1]=1;
    dfs(1,0);
    maxim=0;
    for(i=1;i<=n;i++)
        v[i]=0;
    v[p]=1;
    dfs(p,0);
    g<<maxim;
    return 0;
}
