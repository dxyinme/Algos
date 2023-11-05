#include <cstring>
#include <string>
#include <iostream>
#include "strings/multi-hash.hpp"

int trans(const char &c)
{
  return c;
}

int main()
{
  std::string s1("wnfwfbryfgdohdyeydejdiyydud");
  std::string s2("hdwnfwfbryhuhuhuhuhudjdjdj");
  std::array<std::tuple<long long, long long>, 3> arr;
  arr[0] = {233, 1e8 + 7};
  arr[1] = {233, 998244353};
  arr[2] = {233, 1e9 + 7};

  MultiHash<char, long long, 3>
      mhash1((const char *)s1.c_str(), s1.size(), trans, arr);

  MultiHash<char, long long, 3>
      mhash2((const char *)s2.c_str(), s2.size(), trans, arr);

  auto r1 = mhash1.GetSub(2, 3);
  auto r2 = mhash2.GetSub(4, 5);
  std::cout << s1.substr(2, 2) << "\n";
  std::cout << s2.substr(4, 2) << "\n";
  for (int i = 0; i < 3; i++)
  {
    std::cout << r1[i] << "," << r2[i] << "\n";
  }
}