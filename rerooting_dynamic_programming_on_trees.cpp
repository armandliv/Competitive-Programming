/// https://www.infoarena.ro/problema/asmin
#include<fstream>
#include<vector>
using namespace std;
ifstream f("asmin.in");
ofstream g("asmin.out");
vector<int>a[16002];
int k,v[160002],sol[16002];

void dfs(int x,int tata)
{
    for(auto y:a[x])
    if(y!=tata)
    {
        sol[1]+=(v[y]-v[x]+k)%k;
        dfs(y,x);
    }
}

void muta(int x,int tata)
{
    for(auto y:a[x])
    if(y!=tata)
    {
        sol[y]=sol[x]-(v[y]-v[x]+k)%k-v[x]+(v[x]-v[y]+k)%k+v[y];
        muta(y,x);
    }
}

int main()
{
    int n,i,x,y,minim=1000000000,kk=0;
    f>>n>>k;
    for(i=1;i<=n-1;i++)
    {
        f>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(i=1;i<=n;i++)
        f>>v[i];
    sol[1]=v[1];
    dfs(1,0);
    muta(1,0);
    for(i=1;i<=n;i++)
    if(sol[i]<minim)
        minim=sol[i],kk=1;
    else
    if(minim==sol[i])
        kk++;
    g<<minim<<" "<<kk<<'\n';
    for(i=1;i<=n;i++)
    if(sol[i]==minim)
        g<<i<<" ";
    return 0;
}
