/// https://infoarena.ro/problema/pscpld
#include<bits/stdc++.h>
using namespace std;
ifstream f("pscpld.in");
ofstream g("pscpld.out");
char s[1000002],p[2000002];
int n,manacher[2000002];

void Manacher()
{
    int i,poz=0,st,dr,ok;
    p[1]='*';
    for(i=1;i<=n;i++)
        p[i*2]=s[i],p[i*2+1]='*';
    for(i=1;i<=2*n+1;i++)
    {
        if(poz+manacher[poz]<i)
        {
            poz=i;
            st=i-1;
            dr=i+1;
            while(st>=1&&dr<=2*n+1&&p[st]==p[dr])
            {
                manacher[poz]++;
                st--;
                dr++;
            }
        }
        else
        {
            if(poz+manacher[poz]>i+manacher[poz-(i-poz)])
                manacher[i]=manacher[poz-(i-poz)];
            else
            if(poz+manacher[poz]<i+manacher[poz-(i-poz)])
                manacher[i]=poz+manacher[poz]-i;
            else
            {
                manacher[i]=manacher[poz-(i-poz)];
                st=i-manacher[i]-1;
                dr=i+manacher[i]+1;//poz+manacher[poz]+1
                ok=0;
                while(st>=1&&dr<=2*n+1&&p[st]==p[dr])
                {
                    manacher[i]++;
                    ok=1;
                    st--;
                    dr++;
                }
                if(ok==1)
                    poz=i;
            }
        }
    }
}

int main()
{
    int i;
    long long sol=0;
    f.getline(s+1,1000001);
    n=strlen(s+1);
    Manacher();
    for(i=1;i<=2*n+1;i++)
    if(p[i]=='*')
        sol+=manacher[i]/2;
    else
        sol+=manacher[i]/2+1;
    g<<sol;
    return 0;
}
