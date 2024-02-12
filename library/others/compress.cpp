#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define ALL(v) (v).begin(),(v).end()
#define LB(v, key) lower_bound((v).begin(), (v).end(), key)
template<class t> using vc = vector<t>;

// 座標圧縮
vc<ll> Compress(const vc<ll> &data){
    vc<ll> prov = data;
    sort(ALL(prov));
    prov.erase(unique(ALL(prov)), prov.end());
    vc<ll> res(data.size());
    REP(i, data.size()) {
        res[i] = LB(prov, data[i]) - prov.begin();
    }
    return res;
}
