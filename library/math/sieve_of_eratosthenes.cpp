#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define FOR(i, m, n) for (ll i = m; i <= n; ++i)
template<class t> using vc = vector<t>;

// エラトステネスの篩
// 1 以上 N 以下の整数が素数かどうかを返す
vc<bool> Eratosthenes(ll N) {
    vc<bool> isprime(N+1, true);
    isprime[1] = false;
    FOR(p, 2, N){
        if(!isprime[p])continue;
        for(ll q=p*2; q<=N; q+=p){
            isprime[q] = false;
        }
    }
    return isprime;
}