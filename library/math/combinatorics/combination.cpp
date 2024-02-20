#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, m, n) for (ll i = m; i <= n; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
template<class t> using vc = vector<t>;
template<class t> using vvc = vc<vc<t>>;

// 組み合わせの列挙，v[n][r] = nCr となる
void combination(vvc<ll> &v, ll n, ll r){
    REP(i, v.size()){
        v[i][0] = 1;
        v[i][i] = 1;
    }
    FOR(i, 1, v.size()-1){
        FOR(k, 1, j-1){
            v[j][k] = v[j-1][k-1] + v[j-1][k];
        }
    }
}

// vvc<ll> v(n+1, vc<ll>(n+1, 0));