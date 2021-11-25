/// https://infoarena.ro/problema/evaluare
#include<fstream>
using namespace std;
ifstream f("evaluare.in");
ofstream g("evaluare.out");
char s[100002];
int i;

int termen();
int factor();

int calc()
{
    int x=termen();
    while(s[i]=='+'||s[i]=='-')
    {
        if(s[i]=='+')
        {
            i++;
            x+=termen();
        }
        else
        if(s[i]=='-')
        {
            i++;
            x-=termen();
        }
    }
    i++;
    return x;
}

int termen()
{
    int x=factor();
    while(s[i]=='*'||s[i]=='/')
    {
        if(s[i]=='*')
        {
            i++;
            x*=factor();
        }
        else
        if(s[i]=='/')
        {
            i++;
            x/=factor();
        }
    }
    return x;
}

int factor()
{
    int x=0;
    if(s[i]=='(')
    {
        i++;
        return calc();
    }
    else
    {
        while(s[i]>='0'&&s[i]<='9')
            x=x*10+s[i]-48,i++;
        return x;
    }
}

int main()
{
    int sol;
    f.getline(s+1,100001);
    i=1;
    sol=calc();
    g<<sol;
    return 0;
}

