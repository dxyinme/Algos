// https://www.luogu.com.cn/problem/P2679
#include <iostream>
#include <cstring>
#include <string>
#include <array>

const int mod = 1e9 + 7;
const int M = 204;
const int N = 1004;
const int K = 204;

int f[2][M][K];
int g[M][M][K];

int main()
{
  memset(f, 0, sizeof(f));
  memset(g, 0, sizeof(g));
  std::ios::sync_with_stdio(false);
  int n, m, k;
  std::cin >> n >> m >> k;
  std::string a, b;
  std::cin >> a >> b;

  f[0][0][0] = 1;
  for (int i = 0; i <= m; i++)
    g[i][0][0] = 1;

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= std::min(m, i); j++)
    {
      for (int t = 1; t <= std::min(j, k); t++)
      {
        f[i % 2][j][t] = 0;
        for (int l = 1; l <= j - t + 1; l++)
        {
          if (a[i - l] == b[j - l])
          {
            f[i % 2][j][t] = (f[i % 2][j][t] + g[(i - l + m) % (m)][j - l][t - 1]) % mod;
          }
          else
            break;
        }
        g[i % m][j][t] = (g[(i - 1 + m) % m][j][t] + f[i % 2][j][t]) % mod;
      }
    }
  }
  std::cout << g[n % m][m][k] << std::endl;
  return 0;
}