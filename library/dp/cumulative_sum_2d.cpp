#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (ll i = 0; i < n; ++i)
template<class t> using vc = vector<t>;
template<class t> using vvc = vc<vc<t>>;

// 二次元累積和
vvc<ll> CumulativeSum2D(const vvc<ll> &data, ll h, ll w){
    vvc<ll> sum(h+1, vc<ll>(w+1, 0));
    REP(i, h){
        REP(j, w){
            sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + data[i][j];
        }
    }
    return sum;
}
