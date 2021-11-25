/// https://infoarena.ro/problema/bfs
#include<fstream>
#include<vector>
using namespace std;
ifstream f("bfs.in");
ofstream g("bfs.out");
vector<int> a[100002];
int coada[100002],visited[100002];
int main()
{
    int n,m,s,x,i,st,dr,y;
    f>>n>>m>>s;
    for(i=1;i<=m;i++)
    {
        f>>x>>y;
        a[x].push_back(y);
    }
    st=1;
    dr=1;
    coada[1]=s;
    visited[s]=0;
    while(st<=dr)
    {
        for(i=0;i<a[coada[st]].size();i++)
        if(visited[a[coada[st]][i]]==0&&a[coada[st]][i]!=s)
        {
            coada[++dr]=a[coada[st]][i];
            visited[coada[dr]]=visited[coada[st]]+1;
        }
        st++;
    }
    for(i=1;i<=n;i++)
    {
        if(i==s)
            g<<0;
        else
        if(visited[i]==0)
            g<<-1;
        else
            g<<visited[i];
        g<<" ";
    }
    return 0;
}
