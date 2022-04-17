/// https://codeforces.com/gym/102562/problem/I
//max flow min cut     project selection problem
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 1000000000
using namespace std;
vector<int>a[1002];
int N,s,d,sol,r[1002][1002],tata[1002],mafia[1002],v[1002];
bool viz[1002];
queue<int>q;

inline bool bfs()
{
    int i,x,l;
    for(i=1;i<=N;i++)
        viz[i]=0,tata[i]=0;
    q.push(s);
    viz[s]=1;
    while(!q.empty())
    {
        x=q.front();
        q.pop();
        l=a[x].size();
        for(i=0;i<l;i++)
        if(viz[a[x][i]]==0&&r[x][a[x][i]]>0)
        {
            viz[a[x][i]]=1;
            tata[a[x][i]]=x;
            q.push(a[x][i]);
        }
    }
    return viz[d];
}

inline void flux_maxim()
{
    int i,j,flow,l=a[d].size();
    while(bfs()!=0)
    {
        for(i=0;i<l;i++)
        if((tata[a[d][i]]!=0||a[d][i]==s)&&r[a[d][i]][d]>0)
        {
            flow=r[a[d][i]][d];
            for(j=a[d][i];j!=s;j=tata[j])
            {
                flow=min(flow,r[tata[j]][j]);
                if(flow==0)
                    break;
            }
            if(flow!=0)
            {
                r[a[d][i]][d]-=flow;
                r[d][a[d][i]]+=flow;
                for(j=a[d][i];j!=s;j=tata[j])
                {
                    r[tata[j]][j]-=flow;
                    r[j][tata[j]]+=flow;
                }
                sol+=flow;
            }
        }
    }
}

int main()
{
    int n,m,i,x,y,godfather=0,k;
    cin>>n>>m;
    for(i=1;i<=n;i++)
        cin>>mafia[i];
    for(i=1;i<=m;i++)
        cin>>v[i],godfather+=v[i];
    for(x=1;x<=m;x++)
    {
        cin>>k;
        for(i=1;i<=k;i++)
        {
            cin>>y;
            a[x].push_back(y+m);
            a[y+m].push_back(x);
            r[x][y+m]=INF;
        }
    }
    s=n+m+1;
    d=n+m+2;
    for(i=1;i<=m;i++)
    {
        a[s].push_back(i);
        a[i].push_back(s);
        r[s][i]=v[i];
    }
    for(i=1;i<=n;i++)
    {
        a[i+m].push_back(d);
        a[d].push_back(i+m);
        r[i+m][d]=mafia[i];
    }
    N=n+m+2;
    flux_maxim();
    cout<<godfather-sol;
    return 0;
}
///muchiile pline spre civili sunt alea care nu sunt luate
// iar muchiile pline de la mafioti sunt mafiotii care sunt luati   -> aici am un contraexemplu cand e un singut mafiot si un singur civil si amandoi au acelasi cost
