/// https://infoarena.ro/problema/ciur
#include<fstream>
using namespace std;
ifstream f("ciur.in");
ofstream g("ciur.out");
bool w[2000002];

void ciur()
{
    int i,j;
    w[0]=w[1]=1;
    for(i=4;i<=2000000;i+=2)
        w[i]=1;
    for(i=3;i*i<=2000000;i+=2)
    if(w[i]==0)
    for(j=i*i;j<=2000000;j+=i)
        w[j]=1;
}

int main()
{
    int n,i,k=0;
    f>>n;
    ciur();
    for(i=2;i<=n;i++)
    if(w[i]==0)
        k++;
    g<<k;
    return 0;
}
