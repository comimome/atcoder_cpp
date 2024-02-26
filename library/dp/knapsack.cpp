#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, m, n) for (ll i = (m); i <= (n); ++i)
#define REP(i, n) for (ll i = 0; i < (n); ++i)
template<class t> using vc = vector<t>;

// 個数制限なし最大和ナップサック問題
// O(NW)
vc<ll> knapsack(const vc<ll> &w, const vc<ll> &v, const ll &W) {
    vvc<ll> dp(w.size(), vc<ll>(W+1, 0));
    REP(i, n) {
        REP(j, W+1) {
            if(j >= w[i]) dp[i+1][j] = max(dp[i][j-w[i]] + v[i], dp[i][j]);
            else dp[i+1][j] = dp[i][j];
        }
    }
}