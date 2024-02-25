#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (ll i = 0; i < (n); ++i)
template<class t> using vc = vector<t>;

// ミラー・ラビン素数判定法
// Miller-Rabin primality test
// 乱択アルゴリズム
bool MillerRabin(ll N) {
    if (N == 2) return true;
    if (N == 1 or N % 2 == 0) return false;
    ll M = N - 1;
    ll lsb = M & (-M);
    ll s = log2(lsb);
    ll d = M / lsb;
    vc<ll> test_numbers = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for(auto a : test_numbers) {
        if (a == N) continue;
        ll x = 1;
        REP(i, d){
            x = (x * a) % N;
        }
        ll r = 0;
        if (x == 1) continue;
        while (x != M) {
            x = (x * x) % N;
            r += 1;
            if (x == 1 or r == s) return false;
        }
    }
    return true;
}
