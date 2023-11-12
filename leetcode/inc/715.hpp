#include <iostream>
#include <array>
using namespace std;

namespace leetcode::T715
{
  constexpr int MAX_OP = 1e4;
  constexpr int LOG_MAX = 34;

  struct Node
  {
    int l, r, ls, rs;
    short v;

    Node(int L, int R, int LS, int RS, short V) : l(L), r(R), ls(LS), rs(RS), v(V) {}
    Node()
    {
      ls = -1;
      rs = -1;
      l = -1;
      r = -1;
      v = 0;
    }
  };

  class RangeModule
  {
  private:
    array<Node, MAX_OP * LOG_MAX> tr;
    int cnt;

    void _setV(int x, int a, int b, short v)
    {
      if (v == tr[x].v)
        return;
      int l = tr[x].l;
      int r = tr[x].r;
      // cout << x << ":" << l << "," << r << "," << a << "," << b << "," << tr[x].v << endl;
      if (l == a && r == b)
      {
        tr[x].v = v;
        return;
      }

      int m = (l + r) / 2;
      if (tr[x].ls == -1)
      {
        tr[cnt++] = Node(l, m, -1, -1, tr[x].v);
        tr[x].ls = cnt - 1;
      }
      if (tr[x].rs == -1)
      {
        tr[cnt++] = Node(m + 1, r, -1, -1, tr[x].v);
        tr[x].rs = cnt - 1;
      }
      int ls = tr[x].ls, rs = tr[x].rs;
      if (tr[x].v != -1)
        tr[ls].v = tr[rs].v = tr[x].v;
      if (m >= b)
      {

        _setV(ls, a, b, v);
      }
      else if (m < a)
      {

        _setV(rs, a, b, v);
      }
      else
      {
        _setV(ls, a, m, v);
        _setV(rs, m + 1, b, v);
      }

      if (tr[ls].v == -1 || tr[rs].v == -1)
      {
        tr[x].v = -1;
      }
      else if (tr[ls].v != tr[rs].v)
      {
        tr[x].v = -1;
      }
      else
      {
        tr[x].v = tr[ls].v;
      }
    }

    void _watch(int x, int a, int b)
    {
      _setV(x, a, b, 1);
    }

    void _unwatch(int x, int a, int b)
    {
      _setV(x, a, b, 0);
    }

    short query(int x, int a, int b)
    {
      int l = tr[x].l;
      int r = tr[x].r;
      if (l <= a && b <= r && tr[x].v != -1)
      {
        return tr[x].v;
      }
      int ls = tr[x].ls, rs = tr[x].rs;
      int m = (l + r) / 2;
      if (b <= m)
        return query(ls, a, b);
      else if (a > m)
        return query(rs, a, b);
      else
      {
        short pl = query(ls, a, m);
        if (pl == -1)
          return -1;
        short pr = query(rs, m + 1, b);
        if (pl == pr)
          return pl;
        else
          return -1;
      }
    }

  public:
    RangeModule()
    {
      tr[0] = Node(1, 1e9 + 5, -1, -1, 0);
      cnt = 1;
    }

    void addRange(int left, int right)
    {
      _watch(0, left, right - 1);
    }

    bool queryRange(int left, int right)
    {
      return query(0, left, right - 1) == 1;
    }

    void removeRange(int left, int right)
    {
      _unwatch(0, left, right - 1);
    }
  };

  /**
   * Your RangeModule object will be instantiated and called as such:
   * RangeModule* obj = new RangeModule();
   * obj->addRange(left,right);
   * bool param_2 = obj->queryRange(left,right);
   * obj->removeRange(left,right);
   */

} // namespace leetcode::T715
