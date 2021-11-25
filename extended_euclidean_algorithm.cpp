/// https://infoarena.ro/problema/euclid3
#include<cstdio>
#include<fstream>
#include<cmath>
using namespace std;
FILE *f=fopen("euclid3.in","r");
ofstream g("euclid3.out");
int x,y;
int euclid(int a,int b)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int d;
    d=euclid(b,a%b);
    int xx;
    if(b==d)
    {
        x=1;
        y=a/b-1;
        y-=2*y;
    }
    else
    if(a==d)
    {
        y=0;
        x=a/b-1;
        x-=2*x;
    }
    else
    if(a%b==d)
    {
        x=1;
        y=(a-d)/b;
        if(y>0)
        y-=2*y;
        else
        x=-1;
    }
    else
    {
        xx=x;
        x=y;
        if(y<0)
        y=xx+(a/b)*abs(y);
        else
            y=abs(xx)+(a/b)*y,y-=y*2;
    }
    return d;
}

int main()
{
    int n,a,b,c,i,d;
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d%d%d",&a,&b,&c);
        d=euclid(a,b);
        if(c%d!=0)
            g<<"0 0"<<'\n';
        else
        {
            if((a<0&&b>0)||(a>0&&b<0))
            {
                x-=2*x;
                y-=2*y;
                g<<x*(c/d)<<" "<<y*(c/d)<<'\n';
            }
            else
            g<<x*(c/d)<<" "<<y*(c/d)<<'\n';
        }
    }
    return 0;
}
