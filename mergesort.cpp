/// https://infoarena.ro/problema/algsort
#include<cstdio>
#include<fstream>
using namespace std;
FILE *f=fopen("algsort.in","r");
ofstream g("algsort.out");
int v[500002],w[500002];

void merge_sort(int st,int dr)
{
    if(st!=dr)
    {
        int i,j,k=0,mij=(st+dr)/2;
        merge_sort(st,mij);
        merge_sort(mij+1,dr);
        i=st;
        j=mij+1;
        while(i<=mij&&j<=dr)
        {
            if(v[i]<=v[j])
            {
                w[++k]=v[i];
                i++;
            }
            else
            {
                w[++k]=v[j];
                j++;
            }
        }
        if(i<=mij)
        {
            for(j=i;j<=mij;j++)
                w[++k]=v[j];
        }
        else
        {
            for(i=j;i<=dr;i++)
                w[++k]=v[i];
        }
        for(i=st;i<=dr;i++)
            v[i]=w[i-st+1];
    }
}

int main()
{
    int n,i;
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
        fscanf(f,"%d",&v[i]);
    merge_sort(1,n);
    for(i=1;i<=n;i++)
        g<<v[i]<<" ";
    return 0;
}
