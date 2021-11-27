/// https://infoarena.ro/problema/heavypath
#include<bits/stdc++.h>
using namespace std;
ifstream f("heavypath.in");
ofstream g("heavypath.out");
vector<int>a[100002];
int n,val[100002],dim[100002],niv[100002],tata[100002],head[100002],v[100002],k,poz[100002],aint[400002];

int query(int nod,int st,int dr,int l,int r)
{
    if(st==l&&dr==r)
        return aint[nod];
    else
    {
        int mij=(st+dr)/2;
        if(r<=mij)
            return query(2*nod,st,mij,l,r);
        else
        if(l>mij)
            return query(2*nod+1,mij+1,dr,l,r);
        else
            return max(query(2*nod,st,mij,l,mij),query(2*nod+1,mij+1,dr,mij+1,r));
    }
}

int query(int x,int y)
{
    return query(1,1,n,x,y);
}

void update(int nod,int st,int dr,int index,int value)
{
    if(st==dr)
        aint[nod]=value;
    else
    {
        int mij=(st+dr)/2;
        if(index<=mij)
            update(2*nod,st,mij,index,value);
        else
            update(2*nod+1,mij+1,dr,index,value);
        aint[nod]=max(aint[2*nod],aint[2*nod+1]);
    }
}

void update(int x,int y)
{
    return update(1,1,n,x,y);
}

void dfs(int x)
{
    dim[x]=1;
    for(auto y:a[x])
    if(y!=tata[x])
    {
        tata[y]=x;
        niv[y]=niv[x]+1;
        dfs(y);
        dim[x]+=dim[y];
    }
}

void dfs_greu(int x)
{
    int heavy=0;
    v[++k]=x;
    poz[x]=k;
    for(auto y:a[x])
    if(y!=tata[x]&&dim[y]>dim[heavy])
        heavy=y;
    if(heavy==0)
        return;
    head[heavy]=head[x];
    dfs_greu(heavy);
    for(auto y:a[x])
    if(y!=tata[x]&&y!=heavy)
        dfs_greu(y);
}

void update_heavy(int x,int y)
{
    update(poz[x],y);
}

int query_heavy(int x,int y)
{
    int sol;
    if(head[x]==head[y])
    {
        if(niv[x]>niv[y])
            swap(x,y);
        sol=query(poz[x],poz[y]);
    }
    else
    {
        if(niv[head[x]]<niv[head[y]])
            swap(x,y);
        sol=query(poz[head[x]],poz[x]);
        x=tata[head[x]];
        sol=max(sol,query_heavy(x,y));
    }
    return sol;
}

int main()
{
    int m,i,x,y,p;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>val[i];
    for(i=1;i<=n-1;i++)
    {
        f>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    dfs(1);
    for(i=1;i<=n;i++)
        head[i]=i;
    dfs_greu(1);
    for(i=1;i<=n;i++)
        update_heavy(i,val[i]);
    for(i=1;i<=m;i++)
    {
        f>>p>>x>>y;
        if(p==0)
            update_heavy(x,y);
        else
            g<<query_heavy(x,y)<<'\n';
    }
    return 0;
}
