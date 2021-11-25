/// https://infoarena.ro/problema/deque
#include<fstream>
#include<deque>
using namespace std;
ifstream f("deque.in");
ofstream g("deque.out");
int v[5000002];
deque<int>d;
int main()
{
    int n,i,k;
    long long sol=0;
    f>>n>>k;
    for(i=1;i<=n;i++)
        f>>v[i];
    for(i=1;i<=n;i++)
    {
        if(!d.empty()&&d.front()==i-k)
            d.pop_front();
        while(!d.empty()&&v[i]<v[d.back()])
            d.pop_back();
        d.push_back(i);
        if(i>=k)
            sol+=(long long)v[d.front()];
    }
    g<<sol;
    return 0;
}
