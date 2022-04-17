/// https://open.kattis.com/problems/queryonarray
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
long long ss[320],v[100002],s[320],sum[320],r,x1[320],x2[320],x3[320],a1[320],a2[320],a3[320];
///long long cu long long

long long care(long long x)
{
    return (x-1)/r+1;
}

long long f1(long long x)
{
    return 3*x*x+6*x+2;
}

long long f2(long long x)
{
    return 0-(3*x+3);
}

int main()
{
    long long n,m,i,l,p,st,dr,j,left,right,ll,rr,sol,x,y,semn;
    cin>>n>>m;
    r=sqrtl(n);
    for(i=1;i<=n/r;i++)
    {
        for(j=(i-1)*r+1;j<=i*r;j++)
        {
            ss[i]+=j*(j+1)*(j+2),ss[i]%=MOD;
            a1[i]+=f1(j),a1[i]%=MOD;
            a2[i]+=f2(j),a2[i]%=MOD;
            a3[i]+=1,a3[i]%=MOD;
        }
    }
    for(l=1;l<=m;l++)
    {
        cin>>p>>st>>dr;
        if(p==0)
        {
            sol=0;
            x=care(st);
            y=care(dr);
            if(x!=y)
            {
                left=x+1;
                right=y-1;
                for(i=left;i<=right;i++)
                {
                    sol+=s[i]+sum[i]*ss[i],sol%=MOD;
                    sol-=x1[i]*a1[i]+x2[i]*a2[i]+x3[i]*a3[i];
                    sol%=MOD;
                }
                ll=x*r;
                rr=(y-1)*r+1;
                s[x]+=sum[x]*ss[x];
                s[x]-=x1[x]*a1[x]+x2[x]*a2[x]+x3[x]*a3[x];
                s[x]%=MOD;
                for(i=ll;i>=ll-r+1;i--)
                {
                    v[i]+=sum[x]*i*(i+1)*(i+2);
                    v[i]-=x1[x]*f1(i)+x2[x]*f2(i)+x3[x];
                    v[i]%=MOD;
                }
                sum[x]=0;
                x1[x]=0;
                x2[x]=0;
                x3[x]=0;
                s[y]+=sum[y]*ss[y];
                s[y]-=x1[y]*a1[y]+x2[y]*a2[y]+x3[y]*a3[y];
                s[y]%=MOD;
                for(i=rr;i<=min(n,rr+r-1);i++)
                {
                    v[i]+=sum[y]*i*(i+1)*(i+2);
                    v[i]-=x1[y]*f1(i)+x2[y]*f2(i)+x3[y];
                    v[i]%=MOD;
                }
                sum[y]=0;
                x1[y]=0;
                x2[y]=0;
                x3[y]=0;
                for(i=st;i<=ll;i++)
                    sol+=v[i],sol%=MOD;
                for(i=rr;i<=dr;i++)
                    sol+=v[i],sol%=MOD;
            }
            else
            {
                ll=x*r;
                s[x]+=sum[x]*ss[x];
                s[x]-=x1[x]*a1[x]+x2[x]*a2[x]+x3[x]*a3[x];
                s[x]%=MOD;
                for(i=ll;i>=ll-r+1;i--)
                {
                    v[i]+=sum[x]*i*(i+1)*(i+2);
                    v[i]-=x1[x]*f1(i)+x2[x]*f2(i)+x3[x];
                    v[i]%=MOD;
                }
                sum[x]=0;
                x1[x]=0;
                x2[x]=0;
                x3[x]=0;
                for(i=st;i<=dr;i++)
                    sol+=v[i];
            }
            sol%=MOD;
            if(sol<0)
                sol+=MOD;
            cout<<sol<<'\n';
        }
        else
        {
            semn=1;
            if(p==2)
                semn=-1;
            x=care(st);
            y=care(dr);
            if(x!=y)
            {
                left=x+1;
                right=y-1;
                for(i=left;i<=right;i++)
                {
                    sum[i]+=semn;
                    x1[i]+=(st-1)*semn;
                    x2[i]+=(st-1)*(st-1)*semn;
                    x3[i]+=(st-1)*(st-1)*(st-1)*semn;
                    x1[i]%=MOD;
                    x2[i]%=MOD;
                    x3[i]%=MOD;
                }
                ll=x*r;
                rr=(y-1)*r+1;
                for(i=st;i<=ll;i++)
                {
                    v[i]+=semn*(i-st+1)*(i-st+2)*(i-st+3);
                    v[i]%=MOD;
                    s[x]+=semn*(i-st+1)*(i-st+2)*(i-st+3);
                    s[x]%=MOD;
                }
                for(i=rr;i<=dr;i++)
                {
                    v[i]+=semn*(i-st+1)*(i-st+2)*(i-st+3);
                    v[i]%=MOD;
                    s[y]+=semn*(i-st+1)*(i-st+2)*(i-st+3);
                    s[y]%=MOD;
                }
            }
            else
            {
                for(i=st;i<=dr;i++)
                {
                    v[i]+=semn*(i-st+1)*(i-st+2)*(i-st+3);
                    v[i]%=MOD;
                    s[x]+=semn*(i-st+1)*(i-st+2)*(i-st+3);
                    s[x]%=MOD;
                }
            }
        }
    }
    return 0;
}


