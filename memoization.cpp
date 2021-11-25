/// https://infoarena.ro/problema/podm
#include <fstream>
#include <algorithm>
using namespace std;
ifstream f("podm.in");
ofstream g("podm.out");
const int MAX_N = 500;

long long v[MAX_N + 1];

long long Solve[MAX_N + 1][MAX_N + 1];

long long solve(int st, int dr) {
  if (Solve[st][dr] == 0) {
    if (st + 1 == dr) {
      Solve[st][dr] = 0;
    } else {
      long long op = 1LL << 62;
      for (int i = st + 1; i < dr; i++)
        op = std::min(op, v[st] * v[i] * v[dr] + solve(st, i) + solve(i, dr));
      Solve[st][dr] = op;
    }
  }
  return Solve[st][dr];
}

int main() {
  int n;
  f>>n;
  for (int i = 0; i <= n; i++)
      f>>v[i];
  long long answer = solve(0, n);
  g<<answer;
  return 0;
}
