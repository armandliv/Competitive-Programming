/// https://infoarena.ro/problema/sdo
#include<fstream>
#include<algorithm>
#include<cstdlib>
#include<ctime>
using namespace std;
ifstream f("sdo.in");
ofstream g("sdo.out");
int v[3000002];

int kth_element(int st,int dr,int k)
{
    if(st==dr)
        return v[st];
    int i=st,j=dr,pivot=st+rand()%(dr-st+1),poz;
    swap(v[st],v[pivot]);
    while(i<=j)
    {
        while(i<=j&&v[i]<=v[st])
            poz=i,i++;
        while(i<=j&&v[j]>v[st])
            j--;
        if(i<=j)
            swap(v[i],v[j]),poz=i,i++,j--;
    }
    swap(v[st],v[poz]);
    if(poz-st+1==k)
        return v[poz];
    else
    if(poz-st+1>k)
        return kth_element(st,poz-1,k);
    else
        return kth_element(poz+1,dr,k-(poz-st+1));
}

int main()
{
    int n,k,sol,i;
    f>>n>>k;
    for(i=1;i<=n;i++)
        f>>v[i];
    srand(time(0));
    sol=kth_element(1,n,k);
    g<<sol;
    return 0;
}
