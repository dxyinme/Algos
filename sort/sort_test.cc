#include "sort/sort.hpp"
#include "baselib/log.hpp"
#include "baselib/baselib.hpp"
#include "baselib/minitest.hpp"
#include "baselib/minibench.hpp"

const int MAXN = 1e6;

int arr[MAXN + 10];

int main()
{
  auto sw = baselib::StopWatch();
  baselib::RandomArray(arr, MAXN);
  sort::QuickSort<int>(arr, 0, MAXN, sort::DefaultComparator<int>());
  for (int i = 1; i < MAXN; i++)
  {
    baselib::AssertNotBigger(arr[i - 1], arr[i]);
  }
  std::cout << "QuickSort finished:" << sw.Tick() << " second\n";

  baselib::RandomArray(arr, MAXN);
  sort::MergeSort(arr, 0, MAXN, sort::DefaultComparator<int>());
  for (int i = 1; i < MAXN; i++)
  {
    baselib::AssertNotBigger(arr[i - 1], arr[i]);
  }
  std::cout << "MergeSort finished:" << sw.Tick() << " second\n";

  baselib::RandomArray(arr, MAXN);
  sort::HeapSort(arr, 0, MAXN, sort::DefaultComparator<int>());
  for (int i = 1; i < MAXN; i++)
  {
    baselib::AssertNotBigger(arr[i - 1], arr[i]);
  }
  std::cout << "HeapSort finished:" << sw.Tick() << " second\n";
}