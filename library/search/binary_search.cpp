#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class t> using vc = vector<t>;

// index が条件を満たすかどうか
vc<ll> bs;
bool isOK(ll index, ll key) {
    if (bs[index] > key) return true;
    else return false;
}

// 二分探索
ll binary_search(ll key) {
    ll left = -1; //「index = 0」が条件を満たすこともあるので、初期値は -1
    ll right = (ll)bs.size(); // 「index = a.size()-1」が条件を満たさないこともあるので、初期値は a.size()

    while (right - left > 1) {
        ll mid = left + (right - left) / 2;

        if (isOK(mid, key)) right = mid;
        else left = mid;
        // cout<<left<<" "<<right<<endl;
    }

    /* left は条件を満たさない最大の値、right は条件を満たす最小の値になっている */
    return left;
}