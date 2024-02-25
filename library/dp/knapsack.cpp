#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, m, n) for (ll i = (m); i <= (n); ++i)
#define REP(i, n) for (ll i = 0; i < (n); ++i)
template<class t> using vc = vector<t>;

// 個数制限なしナップサック問題
// O(NW)
vc<ll> knapsack(const vc<ll> &w, const vc<ll> &v, const ll &W) {
    vc<ll> dp(W + 1)
}