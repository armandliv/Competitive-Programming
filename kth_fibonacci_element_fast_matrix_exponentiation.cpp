/// https://infoarena.ro/problema/kfib
#include<fstream>
#define MOD 666013
using namespace std;
ifstream f("kfib.in");
ofstream g("kfib.out");
long long a[5][5],b[5][5],c[5][5],sol[5][5];

void inmultire_matrice(long long a[5][5],long long b[5][5])
{
    long long i,j,k,s;
    for(i=1;i<=2;i++)
    for(j=1;j<=2;j++)
    {
        s=0;
        for(k=1;k<=2;k++)
            s+=a[i][k]*b[k][j],s%=MOD;
        c[i][j]=s;
    }
    for(i=1;i<=2;i++)
    for(j=1;j<=2;j++)
        a[i][j]=c[i][j];
}

void pow_log(long long k)
{
    while(k>0)
    {
        if(k%2==1)
            inmultire_matrice(sol,b);
        inmultire_matrice(b,b);
        k/=2;
    }
}

int main()
{
    long long n;
    f>>n;
    if(n==0)
        g<<0;
    else
    {
        a[1][2]=1;
        b[1][2]=1;
        b[2][1]=1;
        b[2][2]=1;
        sol[1][1]=1;
        sol[2][2]=1;
        pow_log(n-1);
        inmultire_matrice(a,sol);
        g<<a[1][2];
    }
    return 0;
}
