/// https://infoarena.ro/problema/radixsort
#include<bits/stdc++.h>
#define R 65535//2^16-1
using namespace std;
ifstream f("radixsort.in");
ofstream g("radixsort.out");
int v0[10000002],v1[10000002],w[10000002],a[R+2];
inline void rez()
{
    int n,i,A,B,C;
    f>>n>>A>>B>>C;
    v0[1]=B;
    for(i=2;i<=n;i++)
        v0[i]=(1LL*v0[i-1]*A+B)%C;
    for(i=1;i<=n;i++)
    {
        w[i]=v0[i]&R;
        a[w[i]]++;
    }
    for(i=1;i<=R;i++)
        a[i]+=a[i-1];
    for(i=n;i>=1;i--)
        v1[a[w[i]]--]=v0[i];
    memset(a,0,sizeof(a));
    for(i=1;i<=n;i++)
    {
        w[i]=(v1[i]>>16)&R;
        a[w[i]]++;
    }
    for(i=1;i<=R;i++)
        a[i]+=a[i-1];
    for(i=n;i>=1;i--)
        v0[a[w[i]]--]=v1[i];
    for(i=1;i<=n;i+=10)
        g<<v0[i]<<" ";
}

int main()
{
    rez();
    return 0;
}
