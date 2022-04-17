/// https://www.infoarena.ro/problema/stramosi
#include<fstream>
#include<vector>
using namespace std;
ofstream g("stramosi.out");
class InputReader {
  private:
    static const int BUFF_SIZE = 100000;
    FILE *f;
    int bp;
    char buff[BUFF_SIZE];
    inline void nxt() {
      if (++bp == BUFF_SIZE) {
        fread(buff, sizeof(char), BUFF_SIZE, f);
        bp = 0;
      }
    }
  public:
    InputReader (const char *file_name) {
      f = fopen(file_name, "r");
      bp = BUFF_SIZE - 1;
    }
    void close() {
      fclose(f);
    }
    InputReader& operator >> (int &num) {
      num = 0;
      while (isdigit(buff[bp]) == 0&&buff[bp]!='-')
        nxt();
      int semn=1;
      if(buff[bp]=='-')
      {
        semn=-1;
        nxt();
      }
      while (isdigit(buff[bp])) {
        num = num * 10 + (buff[bp] - '0')*semn;
        nxt();
      }
      return *this;
    }
} f("stramosi.in");

vector<int>a[250002];
int p[25],v[250002][25];

void dfs(int x)
{
    int i,l=a[x].size(),j=1,y=x;
    for(i=0;i<l;i++)
        v[a[x][i]][0]=x;
    while(v[y][j-1]!=0)
    {
        for(i=0;i<l;i++)
            v[a[x][i]][j]=v[y][j-1];
        y=v[y][j-1];
        j++;
    }
    for(i=0;i<l;i++)
        dfs(a[x][i]);
}

int query(int x,int y)
{
    int k=0;
    while(y!=0)
    {
        if(y%2==1)
            x=v[x][k];
        y/=2;
        k++;
        if(x==0)
            break;
    }
    return x;
}

int main()
{
    int n,m,i,x,y;
    f>>n>>m;
    p[0]=1;
    for(i=1;i<=20;i++)
        p[i]=p[i-1]*2;
    for(i=1;i<=n;i++)
    {
        f>>x;
        a[x].push_back(i);
    }
    x=a[0].size();
    for(i=0;i<x;i++)
        dfs(a[0][i]);
    for(i=1;i<=m;i++)
    {
        f>>x>>y;
        g<<query(x,y)<<'\n';
    }
    return 0;
}
