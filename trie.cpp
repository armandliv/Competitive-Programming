/// https://infoarena.ro/problema/trie
#include<bits/stdc++.h>
using namespace std;
ifstream f("trie.in");
ofstream g("trie.out");
char s[22];
int k;

struct trie
{
    int sum,fv;
    int v[26];
};
vector<trie>a;

void add(int x,int i)
{
    a[x].sum++;
    if(s[i+1]=='\0')
        a[x].fv++;
    else
    {
        if(a[x].v[s[i+1]-'a']==0)
            a[x].v[s[i+1]-'a']=++k,a.push_back({0,0,0});
        add(a[x].v[s[i+1]-'a'],i+1);
    }
}

void del(int x,int i)
{
    a[x].sum--;
    if(s[i+1]=='\0')
        a[x].fv--;
    else
        del(a[x].v[s[i+1]-'a'],i+1);
}

int ap(int x,int i)
{
    if(s[i+1]=='\0')
        return a[x].fv;
    if(a[x].v[s[i+1]-'a']==0)
        return 0;
    return ap(a[x].v[s[i+1]-'a'],i+1);
}

int pref(int x,int i)
{
    if(a[x].sum==0)
        return max(i-1,0);
    if(s[i+1]=='\0')
        return i;
    if(a[x].v[s[i+1]-'a']==0)
        return i;
    return pref(a[x].v[s[i+1]-'a'],i+1);
}

int main()
{
    int p;
    a.push_back({0,0,0});
    while(f>>p)
    {
        f>>(s+1);
        if(p==0)
            add(0,0);
        else
        if(p==1)
            del(0,0);
        else
        if(p==2)
            g<<ap(0,0)<<'\n';
        else
            g<<pref(0,0)<<'\n';
    }
    return 0;
}
