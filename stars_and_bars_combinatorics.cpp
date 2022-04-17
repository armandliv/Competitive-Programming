/// https://www.infoarena.ro/problema/hagi
#include<fstream>
#define MOD 1000000007
using namespace std;
ifstream f("hagi.in");
ofstream g("hagi.out");
long long fact[2000002];

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
    long long k,n,m,sol,i;
    f>>k>>n>>m;
    fact[0]=1;
    for(i=1;i<=2000000;i++)
        fact[i]=fact[i-1]*i,fact[i]%=MOD;
    sol=fact[k+n-1]*fact[k+m-1];
    sol%=MOD;
    sol*=pow_log(fact[k-1],MOD-2);
    sol%=MOD;
    sol*=pow_log(fact[k-1],MOD-2);
    sol%=MOD;
    sol*=pow_log(fact[n],MOD-2);
    sol%=MOD;
    sol*=pow_log(fact[m],MOD-2);
    sol%=MOD;
    g<<sol;
    return 0;
}
