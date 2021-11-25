/// https://infoarena.ro/problema/strmatch
#include<fstream>
#include<cstring>
#include<algorithm>
using namespace std;
ifstream f("strmatch.in");
ofstream g("strmatch.out");
char s1[2000002],s2[2000002];
int lps[2000002],sol[2000002];
int main()
{
    int n1,n2,i,x,k=0;
    f.getline(s1+1,2000001);
    f.getline(s2+1,2000001);
    n1=strlen(s1+1);
    n2=strlen(s2+1);
    for(i=2;i<=n1;i++)
    {
        x=lps[i-1];
        while(x>0&&s1[x+1]!=s1[i])
            x=lps[x];
        if(s1[x+1]==s1[i])
            x++;
        lps[i]=x;
    }
    x=0;
    for(i=1;i<=n2;i++)
    {
        while(x>0&&s1[x+1]!=s2[i])
            x=lps[x];
        if(s1[x+1]==s2[i])
            x++;
        if(x==n1)
            sol[++k]=i-n1;
    }
    g<<k<<'\n';
    for(i=1;i<=min(k,1000);i++)
        g<<sol[i]<<" ";
    return 0;
}

