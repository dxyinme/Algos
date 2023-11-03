#include <vector>
#include <queue>
#include <tuple>
#include <iostream>

using namespace std;

namespace leetcode::T1368
{
  class Solution
  {
  public:
    int minCost(vector<vector<int>> &grid)
    {
      int n = grid.size(), m = grid[0].size();
      vector<vector<vector<int>>> can(n + m + 1, vector<vector<int>>(n + 1, vector<int>(m + 1, 0)));
      can[0][0][0] = 1;
      // cout << can.size() << "," << can[0].size() << "," << can[0][0].size() << endl;
      using IDX = tuple<int, int, int>;

      queue<IDX> q;
      q.push({0, 0, 0});
      int dx[4] = {0, 0, 1, -1},
          dy[4] = {1, -1, 0, 0};
      while (!q.empty())
      {
        auto now = q.front();
        q.pop();
        int layer = get<0>(now);
        if (layer > n + m - 2)
          continue;
        int x = get<1>(now);
        int y = get<2>(now);
        // cout << ":) " << layer << "," << x << "," << y << ":" << grid[x][y] << endl;
        int directId = grid[x][y] - 1;
        int nx = dx[directId] + x;
        int ny = dy[directId] + y;
        if (nx < 0 || nx >= n || ny < 0 || ny >= m)
        {
          // pass
        }
        else
        {
          if (!can[layer][nx][ny])
          {
            can[layer][nx][ny] = 1;
            q.push({layer, nx, ny});
          }
        }

        for (int i = 0; i < 4; i++)
        {
          if (i == directId)
            continue;
          // cout << i << ",";
          nx = dx[i] + x;
          ny = dy[i] + y;
          if (nx < 0 || nx >= n || ny < 0 || ny >= m)
            continue;
          if (!can[layer + 1][nx][ny])
          {
            can[layer + 1][nx][ny] = 1;
            q.push({layer + 1, nx, ny});
          }
        }
        // cout << endl;
      }
      int ans = -1;
      for (int i = 0; i < n + m - 1; i++)
      {
        if (can[i][n - 1][m - 1])
        {
          ans = i;
          break;
        }
      }
      // cout << "? " << ans << endl;
      return ans == -1 ? (n + m - 2) : ans;
    }
  };
} // namespace leetcode::T1368
