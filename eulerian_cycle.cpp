/// https://infoarena.ro/problema/ciclueuler
#include<fstream>
#include<vector>
#include<stack>
using namespace std;
ifstream f("ciclueuler.in");
ofstream g("ciclueuler.out");
struct elem
{
    int x,muchie;
};
vector<elem>a[100002];
stack<int>st;
int sol[500002],k,p[100002],viz[500002];

int main()
{
    int n,m,i,x,y,l,ok=1;
    f>>n>>m;
    for(i=1;i<=m;i++)
    {
        f>>x>>y;
        a[x].push_back({y,i});
        a[y].push_back({x,i});
    }
    for(i=1;i<=n;i++)
    if(a[i].size()%2==1)
    {
        ok=0;
        break;
    }
    if(ok==1)
    {
        st.push(1);
        while(!st.empty())
        {
            x=st.top();
            l=a[x].size();
            if(p[x]<l)
            {
                if(viz[a[x][p[x]].muchie]==0)
                    st.push(a[x][p[x]].x),viz[a[x][p[x]].muchie]=1;
                p[x]++;
            }
            else
            {
                sol[++k]=x;
                st.pop();
            }
        }
        for(i=k;i>=2;i--)
            g<<sol[i]<<" ";
    }
    else
        g<<-1;
    return 0;
}
