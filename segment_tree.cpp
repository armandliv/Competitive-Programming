/// https://infoarena.ro/problema/arbint
#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("arbint.in");
ofstream g("arbint.out");
int n,aint[400002];

int query(int nod,int st,int dr,int left,int right)
{
    if(st==left&&dr==right)
        return aint[nod];
    else
    {
        int mij=(st+dr)/2;
        if(right<=mij)
            return query(2*nod,st,mij,left,right);
        else
        if(mij<left)
            return query(2*nod+1,mij+1,dr,left,right);
        else
            return max(query(2*nod,st,mij,left,mij),query(2*nod+1,mij+1,dr,mij+1,right));
    }
}

int query(int a,int b)
{
    return query(1,1,n,a,b);
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

void update(int a,int b)
{
    return update(1,1,n,a,b);
}

int main()
{
    int m,i,a,b,p;
    f>>n>>m;
    for(i=1;i<=n;i++)
    {
        f>>a;
        update(i,a);
    }
    for(i=1;i<=m;i++)
    {
        f>>p>>a>>b;
        if(p==0)
            g<<query(a,b)<<'\n';
        else
            update(a,b);
    }
    return 0;
}
