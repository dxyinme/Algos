#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 105;
const int INF = 1e9;
int dis[MAXN][MAXN];

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
      {
        dis[i][j] = 0;
      }
      else
      {
        dis[i][j] = INF;
      }
    }
  }
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    dis[u][v] = w;
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cout << dis[i][j] << "\t";
    }
    cout << "\n";
  }
}