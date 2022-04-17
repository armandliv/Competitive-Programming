/// https://infoarena.ro/problema/euro
/// LI CHAO
//solutia cu convex hull trick nu trebuia sa intre(ca sa fie corecta ar fi trebuit ca pantele dreptelor sa fie monotone pe masura ce creste i)
#include<bits/stdc++.h>
#define INF 1000000000000000
using namespace std;
ifstream f("euro.in");
ofstream g("euro.out");
long long n,v[34570],s[34570],dp[34570];

struct line
{
    long long a,b;
};
line li_chao[140002];//lichao[nod] tine minte care dreapta e mai buna in punctul din mijlocul intervalului [st,dr] (in mij=(st+dr)/2)

long long calc_y(line p,int x)//calculeaza valoare lui y in punctul x pe o dreapta
{
    return p.a*x+p.b;
}

line better(line p1,line p2,int x)
{
    if(calc_y(p1,x)>calc_y(p2,x))
        return p1;
    return p2;
}

line query(int nod,int st,int dr,int x)
{
    if(st==dr)
        return li_chao[nod];
    else
    {
        int mij=(st+dr)/2;
        if(x<=mij)
            return better(li_chao[nod],query(2*nod,st,mij,x),x);//trebuie sa analizam si cazul in care li_chao[nod] e mai bun,deoarece(avand in vedere cum functioneaza update ul) e posibil ca linia aceasta sa fie mai buna pe segmentul[st,mij], dar sa nu fie in nodul 2*nod
        else
            return better(li_chao[nod],query(2*nod+1,mij+1,dr,x),x);
    }
}

void update(int nod,int st,int dr,line linie)
{
    if(st==dr)
        li_chao[nod]=better(li_chao[nod],linie,st);
    else
    {
        int mij=(st+dr)/2,sus_st,sus_mij;
        sus_mij=calc_y(linie,mij)>calc_y(li_chao[nod],mij);//daca line e mai sus decat li_chao[nod] in punctul mij
        sus_st=calc_y(linie,st)>calc_y(li_chao[nod],st);//daca line e mai sus decat li_chao[nod] in punctul st
        if(sus_st==0)
        {
            if(sus_mij==1)
            {
                swap(li_chao[nod],linie);
                update(2*nod,st,mij,linie);
            }
            else
            {
                update(2*nod+1,mij+1,dr,linie);
            }
        }
        else
        {
            if(sus_mij==0)
            {
                update(2*nod,st,mij,linie);
            }
            else
            {
                swap(li_chao[nod],linie);
                update(2*nod+1,mij+1,dr,linie);
            }
        }
    }
}

line best_line(int x)
{
    return query(1,1,n,x);
}

void add_line(line linie)
{
    update(1,1,n,linie);
}

int main()
{
    long long i,t;
    line linie;
    f>>n>>t;
    for(i=1;i<=n;i++)
        f>>v[i],s[i]=s[i-1]+v[i];
    dp[0]=0;
    linie={0,0};
    add_line(linie);
    for(i=1;i<=n;i++)
    {
        dp[i]=calc_y(best_line(i),i)+s[i]*i-t;
        linie={-s[i],dp[i]};
        add_line(linie);
    }
    g<<dp[n];
    return 0;
}
