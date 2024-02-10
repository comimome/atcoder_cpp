#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class t> using vc = vector<t>;
template<class t> using vvc = vc<vc<t>>;
template<class t> using pqg = priority_queue<t, vc<t>, greater<t>>;


constexpr ll INFd = (1LL << 60);
struct Edge{ // 辺の情報
	ll to; // 行先
	ll cost; // コスト
};
using Graph = vvc<Edge>;
using Pair = pair<ll, ll>; // { distance, from }
// ダイクストラ法 (基本実装)
// distances は頂点数と同じサイズ, 全要素 INFd で初期化しておく
void Dijkstra(const Graph& graph, vc<ll>& distances, ll root){
	// 「現時点での最短距離, 頂点」の順に取り出す priority_queue
	// デフォルトの priority_queue は降順に取り出すため std::greater を使う
	pqg<Pair> q;
	q.emplace((distances[root] = 0), root);
	while (!q.empty()){
		const ll distance = q.top().first;
		const ll from = q.top().second;
		q.pop();
		if (distances[from] < distance){ // 最短距離でなければ処理しない
			continue;
		}
		for (const auto& edge : graph[from]){ // 現在の頂点からの各辺について
			const ll d = (distances[from] + edge.cost); // to までの新しい距離
			if (d < distances[edge.to]){ // d が現在の記録より小さければ更新
				q.emplace((distances[edge.to] = d), edge.to);
			}
		}
	}
}