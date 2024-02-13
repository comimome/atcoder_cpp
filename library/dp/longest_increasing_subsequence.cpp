#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define ALL(v) (v).begin(),(v).end()
#define LB(v, key) lower_bound((v).begin(), (v).end(), key)
#define UB(v, key) upper_bound((v).begin(), (v).end(), key)
template<class t> using vc = vector<t>;

// 最長増加部分列，flag = true のとき狭義単調増加，false のとき広義単調増加
ll LIS(const vc<ll> &data, flag){
    vc<ll> dp;
    auto it = dp.begin();
    for(const auto& elem : data){
        if constexpr (flag){
            it = LB(ALL(dp), elem);
        }
        else{
            it = UB(ALL(dp), elem);
        }
        if (it == dp.end()){
            dp.push_back(elem);
        }
        else{
            *it = elem;
        }
    }
    return dp.size();
}