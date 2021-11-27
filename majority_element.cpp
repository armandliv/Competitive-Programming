/// https://infoarena.ro/problema/elmaj
#include<fstream>
using namespace std;
ifstream f("elmaj.in");
ofstream g("elmaj.out");
int v[1000002];
int main()
{
    int n,i,k=0,sol;
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>v[i];
        if(k==0)
        {
            sol=v[i];
            k++;
        }
        else
        if(sol==v[i])
            k++;
        else
            k--;
    }
    k=0;
    for(i=1;i<=n;i++)
    if(sol==v[i])
        k++;
    if(k>=n/2+1)
        g<<sol<<" "<<k;
    else
        g<<-1;
    return 0;
}

