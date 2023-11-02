#include <cstring>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
  string a, b;
  cin >> a >> b;
  vector<int> nxt(a.size() + 5, 0);
  // build next
  int j = 0, len = a.size();
  for (int i = 2; i <= len; i++)
  {
    while (j > 0 && a[j] != a[i - 1])
      j = nxt[j];
    if (a[j] == a[i - 1])
    {
      j++;
    }
    nxt[i] = j;
  }
  for (int i = 0; i <= len; i++)
    cout << nxt[i] << ",";
  cout << endl;
  j = 0;
  for (int i = 0; i < b.size(); i++)
  {
    while (j > 0 && a[j] != b[i])
      j = nxt[j];
    if (a[j] == b[i])
      j++;
    if (j == len)
    {
      cout << "Yes\n";
      return 0;
    }
  }
}