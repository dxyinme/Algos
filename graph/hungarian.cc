#include <iostream>
#include <array>
#include <cstdio>

const int MAXN = 504;
const int MAXM = 504;
int n, m, e;
std::array<std::array<int, MAXM>, MAXN> g;
std::array<int, MAXM> p;
std::array<short, MAXM> vis;

bool dfs(int x)
{
  for (int i = 0; i < m; i++)
  {
    if (g[x][i] && !vis[i])
    {
      vis[i] = 1;
      if (p[i] == -1 || dfs(p[i]))
      {
        p[i] = x;
        return true;
      }
    }
  }
  return false;
}

int main()
{
  scanf("%d%d%d", &n, &m, &e);
  for (int i = 0; i < m; i++)
    p[i] = -1;
  for (int i = 0; i < e; i++)
  {
    int u, v;
    scanf("%d%d", &u, &v);
    u--;
    v--;
    g[u][v] = 1;
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
      vis[j] = 0;
    dfs(i);
  }
  int count = 0;
  for (int i = 0; i < m; i++)
    if (p[i] != -1)
      ++count;
  printf("%d\n", count);
  return 0;
}