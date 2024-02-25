#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 素数判定
// O(N)
bool is_prime(ll N) {
    if (N == 1) return false;
    for (ll i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
    }
    return true;
}
