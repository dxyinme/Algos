#include <cstdio>
#include <functional>
#include <vector>
#include <array>
#include <tuple>
#include <iostream>

template <
    typename T = char,
    typename HashValueT = int,
    int ModCount = 1>
class MultiHash
{
public:
  const T *original_;
  size_t length_;
  std::function<HashValueT(const T &)> processor_;
  std::array<std::tuple<HashValueT, HashValueT>, ModCount> mods_;

  std::array<std::vector<HashValueT>, ModCount> prefix_;
  std::array<std::vector<HashValueT>, ModCount> fac_;

  void _init()
  {
    for (size_t mods_idx = 0; mods_idx < ModCount; mods_idx++)
    {
      auto &pre = prefix_[mods_idx];
      auto &fac = fac_[mods_idx];
      auto &mod = std::get<1>(mods_[mods_idx]);
      auto &bulk = std::get<0>(mods_[mods_idx]);

      pre.assign(length_ + 3, (HashValueT)0);
      fac.assign(length_ + 3, (HashValueT)0);
      fac[0] = 1;
      for (size_t i = 0; i < length_; i++)
      {
        if (i > 0)
          fac[i] = (fac[i - 1] * bulk) % mod;
        pre[i + 1] = (pre[i] * bulk % mod + processor_(original_[i])) % mod;
      }
    }
  }

  std::array<HashValueT, ModCount> GetSub(std::size_t L, std::size_t R)
  {
    std::array<HashValueT, ModCount> result;

    for (size_t idx = 0; idx < ModCount; idx++)
    {
      auto &pre = prefix_[idx];
      auto &fac = fac_[idx];
      auto &mod = std::get<1>(mods_[idx]);
      result[idx] = ((pre[R + 1] - 1LL * pre[L] * fac[R + 1 - L] % mod) % mod + mod) % mod;
    }

    return result;
  }

  MultiHash(
      const T *s,
      std::size_t length,
      std::function<HashValueT(const T &)> processor,
      const std::array<std::tuple<HashValueT, HashValueT>, ModCount> &mods) : original_(s), length_(length), processor_(processor), mods_(mods)
  {
    _init();
  }
  ~MultiHash() {}
};