#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (ll i = 0; i < n; ++i)
template<class t> using vc = vector<t>;

// 一次元累積和
vc<ll> CumulativeSum(const vc<ll> &data, ll n){
    vc<ll> sum(n+1, 0);
    REP(i, n){
        sum[i+1] = sum[i] + data[i+1];
    }
    return sum;
}