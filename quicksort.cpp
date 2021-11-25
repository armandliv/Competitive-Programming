/// https://infoarena.ro/problema/algsort
#include<cstdio>
#include<fstream>
using namespace std;
FILE *f=fopen("algsort.in","r");
ofstream g("algsort.out");
int v[500002],w[500002];

inline void quick_sort(int st,int dr)
{
    if(st<dr)
    {
        int i=st,j=dr,k=0,mij=(st+dr)/2,poz;
        for(k=st;k<=dr;k++)
        {
            if(v[k]<v[mij])
            {
                w[i++]=v[k];
            }
            else
            if(v[k]>v[mij])
            {
                w[j--]=v[k];
            }
        }
        for(k=i;k<=j;k++)
            w[k]=v[mij];
        poz=(i+j)/2;
        for(i=st;i<=dr;i++)
            v[i]=w[i];
        quick_sort(st,poz);
        quick_sort(poz+1,dr);
    }
}

int main()
{
    int n,i;
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
        fscanf(f,"%d",&v[i]);
    quick_sort(1,n);
    for(i=1;i<=n;i++)
        g<<v[i]<<" ";
    return 0;
}
