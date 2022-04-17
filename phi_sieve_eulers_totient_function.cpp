/// https://www.infoarena.ro/problema/farey
#include<fstream>
#include<algorithm>
#define eps 0.0000000001
using namespace std;
ifstream f("farey.in");
ofstream g("farey.out");
int n,phi[40002];
inline int rez(long double x)
{
    int i,sol=0,a,j;
    for(i=2;i<=n;i++)
    {
        a=(long double)i*x;
        phi[i]=min(i-1,a);
    }
    for(i=2;i<=n;i++)
    {
        sol+=phi[i];
        for(j=2*i;j<=n;j+=i)
            phi[j]-=phi[i];
    }
    return sol;
}

int main()
{
    int k,z,a,i,sola=0,solb=1;
    long double st,dr,mij,x;
    f>>n>>k;
    st=0;
    dr=1;
    while(dr-st>=eps)
    {
        mij=(st+dr)/2;
        z=rez(mij);
        if(z<k)
            st=mij+eps;
        else
        {
            dr=mij-eps;
            x=mij;
        }
    }
    for(i=2;i<=n;i++)
    {
        a=(long double)i*x;
        if(a*solb>sola*i)
            sola=a,solb=i;
    }
    g<<sola<<" "<<solb;
    return 0;
}

