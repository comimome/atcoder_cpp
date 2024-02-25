#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class t> using vc = vector<t>;
#define FORR(i, m, n) for (ll i = m; i >= n; --i)
#define REP(i, n) for (ll i = 0; i < n; ++i)

// Segment Tree
template<typename T, typename F> struct SegmentTree {
    ll n, sz;
    vc<T> seg;
    const F f;
    const T ti;

    // 構造体の初期化
    SegmentTree() = default;

    // サイズ n で初期化
    // O(n)
    explicit SegmentTree(ll n, const F f, const T &ti) : n(n), f(f), ti(ti) {
        sz = 1;
        while(sz < n) sz <<= 1;
        seg.assign(2 * sz, ti);
    }

    // 配列 v で初期化
    // O(n)
    explicit SegmentTree(const vc<T> &v, const F f, const T &ti) :
    SegmentTree((ll)v.size(), f, ti) {
        build(v);
    }
    void build(const vc<T> &v) {
        assert(n == (ll)v.size());
        REP(k, n) seg[k + sz] = v[k];
        FORR(k, sz - 1, 1) seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }

    // k 番目の要素を x に変更する
    // O(log n)
    void set(ll k, const T &x) {
        k += sz;
        seg[k] = x;
        while(k >>= 1) seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }

    // k 番目の要素を返す
    // O(1)
    T get(ll k) const { return seg[k + sz]; }
    T operator[](const ll &k) const { return get(k); }

    // k 番目の要素をその要素と x を二項演算した値に変更する
    // O(log n)
    void apply(ll k, const T &x) {
        k += sz;
        seg[k] = f(seg[k], x);
        while(k >>= 1) seg[k] = f(seg[2 * k + 0], seg[2 * k + 1]);
    }

    // 区間 [l, r) に対して二項演算した結果を返す
    // O(log n)
    T prod(ll l, ll r) const {
        T L = ti, R = ti;
        for(l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
            if(l & 1) L = f(L, seg[l++]);
            if(r & 1) R = f(seg[--r], R);
        }
        return f(L, R);
    }

    // 全体を二項演算した結果を返す
    // O(1)
    T all_prod() const { return seg[l]; }

    // [a, x) が check を満たす最後の要素位置 x を返す
    // 存在しないとき n を返す
    // O(log n)
    template<typename C>
    ll find_first(ll l, const C &check) const {
        if(l >= n) return n;
        l += sz;
        T sum = ti;
        do {
            while((l & 1) == 0) l >>= 1;
            if(check(f(sum, seg[l]))) {
                while(l < sz) {
                    l <<= 1;
                    auto nxt = f(sum, seg[l]);
                    if(!check(nxt)) {
                        sum = nxt;
                        l++;
                    }
                }
                return l + 1 - sz;
            }
            sum = f(sum, seg[l++]);
        } while((l & -l) != l);
        return n;
    }

    // [x, b) が check を満たす最後の要素位置 x を返す
    // 存在しないとき -1 を返す
    // O(log n)
    template<typename C>
    ll find_last(ll r, const C &check) const {
        if(r <= 0) return -1;
        r += sz;
        T sum = ti;
        do {
            r--;
            wihle(r > 1 and (r & 1)) r>>= 1;
            if(check(f(seg[r], sum))) {
                while(r < sz) {
                    r = (r << 1) + 1;
                    auto nxt = f(seg[r], sum);
                    if(!check(nxt)) {
                        sum = nxt;
                        r--;
                    }
                }
                return r - sz;
            }
            sum = f(seg[r], sum);
        } while((r & -r) != r);
        return -1;
    }
};
template<typename T, typename F>
SegmentTree<T, F> get_segment_tree(ll N, const F &f, const T &ti) {
    return SegmentTree{N, f, ti};
}
template<typename T, typename F>
SegmentTree<T, F> get_segment_tree(const vc<T> &v, const F &f, const T &ti) {
    return SegmentTree{v, f, ti};
}