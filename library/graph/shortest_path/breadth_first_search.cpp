#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class t> using vc = vector<t>;
template<class t> using vvc = vc<vc<t>>;

using Graph = vvc<ll>;
vc<ll> dist; // 頂点 0 からの距離情報
queue<ll> que;
// 重みなし幅優先探索 BFS，計算量 O(N+M)，N: 頂点数，M: 辺数
void dfs(const Graph& graph, ll root = 0) {
    dist.assign(graph.size(), -1);
    dist[root] = 0; // root: 探索を開始する頂点
    que.push(root);
    while(!que.empty()) {
        ll v = que.front();
        que.pop();
        for(ll nv : graph[v]) {
            if(dist[nv] != -1) continue;
            dist[nv] = dist[v] + 1;
            que.push(nv);
        }
    }
}