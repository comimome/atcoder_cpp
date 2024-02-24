#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 素因数分解，O(root(N))
map<ll, ll> prime_factor(ll N) {
    map<ll, ll> ret;
    for(ll i=2; i*i<=N; i++){
        while(N%i==0){
            ret[i]++;
            N/=i;
        }
    }
    if(N!=1)ret[N]=1;
    return ret;
}