/// https://infoarena.ro/problema/aria
#include<fstream>
#include<iomanip>
using namespace std;
ifstream f("aria.in");
ofstream g("aria.out");
struct elem
{
    long double x,y;
};
elem v[100002];

long double calc(int a,int b)
{
    long double sol;
    sol=v[a].x*v[b].y-v[a].y*v[b].x;
    sol/=2;
    return sol;
}

int main()
{
    int n,i;
    long double sol=0;
    f>>n;
    for(i=1;i<=n;i++)
        f>>v[i].x>>v[i].y;
    for(i=1;i<n;i++)
        sol+=calc(i,i+1);
    sol+=calc(n,1);
    g<<fixed<<setprecision(5)<<sol;
    return 0;
}
