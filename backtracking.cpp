/// https://infoarena.ro/problema/combinari
#include <fstream>
using namespace std;
ifstream f("combinari.in");
ofstream g("combinari.out");

int v[20],n,k;

void bk(int p)
{
    int i,j;
    for (i=v[p-1]+1;i<=p+n-k;i++)
    {
        v[p]=i;
        if(p==k)
        {
            for(j=1;j<=k;j++)
                g<<v[j]<<" ";
            g<<'\n';
        }
        else
        if(p+1<=k)
            bk(p+1);
    }
}

int main()
{
    f>>n>>k;
    bk(1);
    return 0;
}
