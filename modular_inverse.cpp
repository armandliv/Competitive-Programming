/// https://infoarena.ro/problema/inversmodular
#include<fstream>
#include<cmath>
using namespace std;
ifstream f("inversmodular.in");
ofstream g("inversmodular.out");
long long MOD;

long long pow_log(long long a,long long k)
{
    long long sol=1;
    while(k!=0)
    {
        if(k%2==1)
            sol*=a,sol%=MOD;;
        a*=a;
        a%=MOD;
        k/=2;
    }
    return sol;
}

int main()
{
    long long a,n,sol,i;
    f>>a>>n;
    sol=n;
    MOD=n;
    for(i=2;i*i<=n;i++)
    if(n%i==0)
    {
        while(n%i==0)
            n/=i;
        sol/=i;
        sol*=(i-1);
    }
    if(n!=1)
        sol/=n,sol*=(n-1);
    sol=pow_log(a,sol-1);
    g<<sol;
    return 0;
}
