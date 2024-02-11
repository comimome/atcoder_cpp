#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class t> using vc = vector<t>;
#define FORR(i, m, n) for (ll i = m; i >= n; --i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

// Segment Tree
template<typename T, typename F> struct SegmentTree {
    ll n, sz;
    vc<T> seg;
    const F f;
    const T ti;
    // 構造体の初期化
    SegmentTree() = default;
};