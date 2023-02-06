// problem from
// https://www.luogu.com.cn/problem/P3385
#include <cstdio>
#include <vector>
#include <queue>
#include <array>
#include <cstdlib>

template <typename WeightType>
class Edge
{
private:
public:
  int f_;
  int t_;
  WeightType w_;

  Edge() = default;
  Edge(int from, int to, int weight)
      : f_(from),
        t_(to), w_(weight) {}

  int From() const
  {
    return f_;
  }
  int To() const
  {
    return t_;
  }
  WeightType Weight() const
  {
    return w_;
  }
};

template <int N, typename WeightType>
class Graph
{
private:
  std::array<std::vector<Edge<WeightType>>, N> g_;

public:
  void Add(const Edge<WeightType> &e)
  {
    g_[e.From()].push_back(e);
  }

  bool HasRing(int start, int n, WeightType INF) const
  {
    std::queue<int> q;
    std::array<int, N> visit_count;
    std::array<int, N> dist;
    for (int i = 0; i < n; i++)
    {
      dist[i] = INF;
      visit_count[i] = 0;
    }
    dist[start] = 0;
    q.push(start);
    visit_count[start] = 1;
    while (!q.empty())
    {
      int x = q.front();
      q.pop();
      if (visit_count[x] > n)
      {
        return true;
      }
      for (const auto &e : g_[x])
      {
        if (dist[e.To()] > dist[x] + e.Weight())
        {
          dist[e.To()] = dist[x] + e.Weight();
          visit_count[e.To()]++;
          q.push(e.To());
        }
      }
    }
    return false;
  }
};

const int MAXN = 2004;
const int INF = 2e9 + 7;

void Work()
{
  int n, m;
  Graph<MAXN, int> g;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    u--;
    v--;
    if (w >= 0)
    {
      g.Add(Edge<int>(u, v, w));
      g.Add(Edge<int>(v, u, w));
    }
    else
    {
      g.Add(Edge<int>(u, v, w));
    }
  }
  if (g.HasRing(0, n, INF))
  {
    puts("YES");
  }
  else
  {
    puts("NO");
  }
}

int main()
{
  int T;
  scanf("%d", &T);
  while (T--)
    Work();
  return 0;
}