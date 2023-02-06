// problem url
// https://www.luogu.com.cn/problem/P4779

#include <vector>
#include <queue>
#include <array>
#include <cstdio>
#include <tuple>

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

  void Dijksta(int start, WeightType INF, std::array<WeightType, N> &dist) const
  {
    std::array<short, N> vis;
    using PII = std::tuple<WeightType, int>;
    std::priority_queue<PII, std::vector<PII>, std::greater<PII>> pq;

    for (int i = 0; i < N; i++)
    {
      dist[i] = INF;
      vis[i] = 0;
    }
    dist[start] = 0;

    pq.push({dist[start], start});
    while (!pq.empty())
    {
      auto top = pq.top();
      pq.pop();
      int x = std::get<1>(top);
      if (vis[x])
        continue;
      vis[x] = 1;
      for (const auto &e : g_[x])
      {
        if (dist[e.To()] > dist[x] + e.Weight())
        {
          dist[e.To()] = dist[x] + e.Weight();
          pq.push({dist[e.To()], e.To()});
        }
      }
    }
  }
};

int main()
{
  const int MAXN = 1e5 + 4;
  const int INF = 1e9 + 7;
  Graph<MAXN, int> g;
  int n, m, s;
  scanf("%d%d%d", &n, &m, &s);
  // from 0 -> n-1
  s--;

  for (int i = 0; i < m; i++)
  {
    Edge<int> e;
    scanf("%d%d%d", &e.f_, &e.t_, &e.w_);
    e.f_--;
    e.t_--;

    g.Add(e);
  }
  std::array<int, MAXN> dist;
  g.Dijksta(s, INF, dist);
  for (int i = 0; i < n; i++)
  {
    printf("%d%c", dist[i], i == n - 1 ? '\n' : ' ');
  }
  return 0;
}