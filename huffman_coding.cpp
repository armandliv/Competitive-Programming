/// https://infoarena.ro/problema/huffman
#include<fstream>
#include<queue>
using namespace std;
ifstream f("huffman.in");
ofstream g("huffman.out");
long long v[2000002],sol[2000002];
int a[2000002][2],n,h[2000002];
queue<int>q1,q2;
void dfs(int x)
{
    if(x>n)
    {
        sol[a[x][0]]=sol[x]*2+1;
        sol[a[x][1]]=sol[x]*2;
        h[a[x][0]]=h[x]+1;
        h[a[x][1]]=h[x]+1;
        dfs(a[x][0]);
        dfs(a[x][1]);
    }
}

int main()
{
    int i,k,x,y;
    long long s=0;
    f>>n;
    for(i=1;i<=n;i++)
        f>>v[i],q1.push(i);
    k=n;
    while(q1.size()+q2.size()>=2)
    {
        k++;
        x=0;
        y=0;
        while(y<2&&!q1.empty()&&!q2.empty())
        {
            if(v[q1.front()]<v[q2.front()])
            {
                x=q1.front();
                q1.pop();
            }
            else
            {
                x=q2.front();
                q2.pop();
            }
            v[k]+=v[x];
            a[k][y]=x;
            y++;
        }
        while(y<2)
        {
            if(q1.empty())
            {
                x=q2.front();
                q2.pop();
            }
            else
            {
                x=q1.front();
                q1.pop();
            }
            v[k]+=v[x];
            a[k][y]=x;
            y++;
        }
        q2.push(k);
    }
    dfs(k);
    for(i=1;i<=n;i++)
        s+=(long long)v[i]*h[i];
    g<<s<<'\n';
    for(i=1;i<=n;i++)
        g<<h[i]<<" "<<sol[i]<<'\n';
    return 0;
}
