#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class t> using vc = vector<t>;
template<class t> using vvc = vc<vc<t>>;

using Graph = vvc<ll>;
vc<bool> seen;
bool seen_assign = true;
// 深さ優先探索 DFS，頂点 v を始点とする
void dfs(const Graph& graph, ll v) {
    if(seen_assign){
        seen.assign(graph.size(), false);
        seen_assign = false;
    }
    seen[v] = true;
    for(auto next_v : graph[v]) {
        if(seen[next_v]) continue;
        dfs(graph, next_v);
    }
}