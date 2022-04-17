/// https://www.pbinfo.ro/probleme/1512/mars
#include<iostream>
using namespace std;
int v[200002];
int main()
{
    int n,m,i,s,d,x;
    cin>>n>>m;
    for(i=1;i<=m;i++)
    {
        cin>>s>>d>>x;
        v[s]+=x;
        v[d+1]-=x;
    }
    s=0;
    for(i=1;i<=n;i++)
    {
        s+=v[i];
        cout<<s<<" ";
    }
    return 0;
}
