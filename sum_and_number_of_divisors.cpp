/// https://infoarena.ro/problema/ssnd
#include<fstream>
#include<cmath>
#define MOD 9973
using namespace std;
ifstream f("ssnd.in");
ofstream g("ssnd.out");
bool w[1000002];
unsigned long long v[1000002],m;

void rez(unsigned long long x)
{
    unsigned long long i,k=1,s=1,e,z;
    for(i=1;v[i]<=sqrtl(x)&&x!=1&&i<=m;i++)
    {
        e=0;
        while(x%v[i]==0)
        {
            e++;
            x/=v[i];
        }
        if(e!=0)//nu e nevoie
        {
            k*=e+1;
            if(e==1)
                s*=v[i]+1;//am simplificat formula ca sa nu folosesc invers modular
            else
            {
                z=1;
                e++;
                while(e!=0)
                {
                    z*=v[i];
                    e--;
                }
                z--;
                z/=v[i]-1;
                s*=z;
            }
            s%=MOD;
        }
    }
    if(x!=1)
    {
        k*=2;
        s*=x+1;//am simplificat formula ca sa nu folosesc invers modular
    }
    s%=MOD;
    g<<k<<" "<<s<<'\n';
}

void ciur()
{
    unsigned long long i,j;
    w[0]=w[1]=1;
    for(i=4;i<=1000000;i+=2)
        w[i]=1;
    for(i=3;i*i<=1000000;i+=2)
    if(w[i]==0)
    for(j=i*i;j<=1000000;j+=i)
        w[j]=1;
    for(i=2;i<=1000000;i++)
    if(w[i]==0)
        v[++m]=i;
}

int main()
{
    unsigned long long n,i,x;
    f>>n;
    ciur();
    for(i=1;i<=n;i++)
    {
        f>>x;
        rez(x);
    }
    return 0;
}
