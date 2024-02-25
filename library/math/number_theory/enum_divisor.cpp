#include <bits/stdc++.h>
using namespace std;

// 約数列挙
// O(root(N))
vector<long long> enum_divisor(long long N) {
  vector<long long> res;
  for (long long i = 1; i * i <= N; ++i) {
    if (N % i == 0) {
      res.push_back(i);
      if (N/i != i) res.push_back(N/i);
    }
  }
  sort(res.begin(), res.end());
  return res;
}