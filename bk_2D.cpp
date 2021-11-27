/// https://infoarena.ro/problema/damesah
#include<bits/stdc++.h>
using namespace std;
ifstream f("damesah.in");
ofstream g("damesah.out");
int n,sol,st[15],col[15];

void afis()
{
    int i;
    if(sol==0)
    {
        for(i=1;i<=n;i++)
            g<<st[i]<<" ";
        g<<'\n';
    }
    sol++;
}

bool verif(int p)
{
    int i;
    for(i=1;i<p;i++)
    if(p-i==abs(st[p]-st[i]))
        return 0;
    return 1;
}

void bk(int p)
{
    int i;
    for(i=1;i<=n;i++)
    if(col[i]==0)
    {
        st[p]=i;
        col[i]=1;
        if(verif(p)==1)
        {
            if(p==n)
                afis();
            else
                bk(p+1);
        }
        col[i]=0;
    }
}

int main()
{
    f>>n;
    bk(1);
    g<<sol;
    return 0;
}
