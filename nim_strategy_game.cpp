/// https://infoarena.ro/problema/nim
#include<fstream>
using namespace std;
ifstream f("nim.in");
ofstream g("nim.out");

int main()
{
    int t,i,j,n,sol,x;
    f>>t;
    for(j=1;j<=t;j++)
    {
        f>>n;
        sol=0;
        for(i=1;i<=n;i++)
        {
            f>>x;
            sol^=x;
        }
        if(sol==0)
            g<<"NU"<<'\n';
        else
            g<<"DA"<<'\n';
    }
    return 0;
}

