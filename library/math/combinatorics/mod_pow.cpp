#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, m, n) for (ll i = m; i <= n; ++i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
template<class t> using vc = vector<t>;
template<class t> using vvc = vc<vc<t>>;
const int mod93 = 998244353;
const int mod17 = 1000000007;

ll mod_pow(ll x, ll y, int mod){
    ll res=1;
    REP(i, y){
        res = res * x % mod;
    }
    return res;
}
