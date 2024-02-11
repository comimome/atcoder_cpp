#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class t> using vc = vector<t>;
template<class t> using vvc = vc<vc<t>>;
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define RV(v) reverse((v).begin(), (v).end())

using Graph = vvc<ll>;
vc<bool> seen;
vc<ll> order; // 結果
// トポロジカルソート，DFSによる実装
void ts_func(const Graph& graph, ll v){
    seen.assign(graph.size(), false);
    REP(i,v) {
        if(seen[v]) continue;
        topological_sort(graph, v);
    }
    RV(order);
}
void topological_sort(const Graph& graph, ll v) {
    seen[v] = true;
    for(auto next_v : graph[v]) {
        if(seen[next_v]) continue;
        topological_sort(graph, v);
    }
    order.push_back(v);
}