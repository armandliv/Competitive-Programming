/// https://infoarena.ro/problema/lgput
#include<fstream>
using namespace std;
ifstream f("lgput.in");
ofstream g("lgput.out");
const long long MOD=1999999973;

long long power(long long b,long long exp)
{
    long long i,ans=1,aux=b;
    for(i=1;i<=exp;i*=2)
    {
        if(exp&i)///daca bitul respectiv se gaseste in exp (=1)
        {
            ans=ans*aux;
            ans%=MOD;
        }
        aux*=aux;
        aux%=MOD;
    }
    return ans;
}

int main()
{
    long long n,p;
    f>>n>>p;
    g<<power(n,p);
    return 0;
}
