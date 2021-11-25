/// https://infoarena.ro/problema/rmq
#include<fstream>
#include<algorithm>
using namespace std;
ifstream f("rmq.in");
ofstream g("rmq.out");
int n,rmq[20][100002],p[20],e[100002];

void calc()
{
    int i,x=2,k=1;
    while(x<=n)
    {
        for(i=1;i<=n-x+1;i++)
            rmq[k][i]=min(rmq[k-1][i],rmq[k-1][i+x/2]);
        x*=2;
        k++;
    }
}

int main()
{
    int m,i,x=1,k=0,y,z;
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>rmq[0][i];
    for(i=1;i<=n;i++)
    {
        if(x*2==i)
            x*=2,k++;
        e[i]=k;
        p[k]=x;
    }
    calc();
    for(i=1;i<=m;i++)
    {
        f>>x>>y;
        k=e[y-x+1];
        z=p[k];
        g<<min(rmq[k][x],rmq[k][y-z+1])<<'\n';
    }
    return 0;
}
