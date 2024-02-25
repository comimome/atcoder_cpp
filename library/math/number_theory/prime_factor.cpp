#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class t> using vc = vector<t>;

// 素因数分解
// O(root(N))
// map を返す
map<ll, ll> prime_factor(ll N) {
    map<ll, ll> res;
    for(ll i=2; i*i<=N; i++){
        while(N%i==0){
            res[i]++;
            N/=i;
        }
    }
    if(N!=1)res[N]=1;
    return res;
}

// 素因数分解
// O(root(N))
// vector<pair> を返す
vc<pair<ll, ll>> prime_factorize(ll N) {
    vc<pair<ll, ll>> res;
    for(ll i=2; i*i<=N; i++){
        if(N%i != 0) continue;
        ll ex = 0;
        while(N%i == 0){
            ex++;
            N /= i;
        }
        res.push_back({i, ex});
    }
    if(N != 1) res.push_back({N, 1});
    return res;
}