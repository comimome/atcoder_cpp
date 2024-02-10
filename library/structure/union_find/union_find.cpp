#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Union-Find
struct UnionFind
{
    vector<ll> par, rank, siz;
    // 構造体の初期化
    UnionFind(ll n) : par(n, -1), rank(n, 0), siz(n, 1) {}
    // 根を求める
    ll root(ll x) {
        if (par[x] == -1) return x;
        else return par[x] = root(par[x]);
    }
    // x と y が同じグループに属するか (= 根が一致するか)
    bool issame(ll x, ll y) {
        return root(x) == root(y);
    }
    // x を含むグループと y を含むグループを併合する
    bool unite(ll x, ll y) {
        ll rx = root(x), ry = root(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) swap(rx, ry);
        par[ry] = rx;
        if (rank[rx] == rank[ry]) rank[rx]++;
        siz[rx] += siz[ry];
        return true;
    }
    // x を含む根付き木のサイズを求める
    ll size(ll x) {
        return siz[root(x)];
    }
};
