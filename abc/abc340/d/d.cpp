#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define FOR(i, m, n) for (ll i = m; i <= n; ++i)
#define FORR(i, m, n) for (ll i = m; i >= n; --i)
#define REP(i, n) for (ll i = 0; i < n; ++i)
#define REPR(i, n) for (ll i = n; i >= 0; --i)
#define ALL(v) (v).begin(),(v).end()
#define RV(v) reverse((v).begin(), (v).end())
#define BS(v, key) binary_search((v).begin(), (v).end(), key)
#define LB(v, key) lower_bound((v).begin(), (v).end(), key)
#define UB(v, key) upper_bound((v).begin(), (v).end(), key)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))
const int mod93 = 998244353;
const int mod17 = 1000000007;
template<class t> using vc = vector<t>;
template<class t> using vvc = vc<vc<t>>;
template<class t> using vvvc = vc<vc<vc<t>>>;
template<class t> using pq = priority_queue<t>;
template<class t> using pqg = priority_queue<t, vc<t>, greater<t>>;
template<class t, class u> using um = unordered_map<t, u>;
template<int MOD> struct Fp {
    long long val;
    constexpr Fp(long long v = 0) noexcept : val(v % MOD) {
        if (val < 0) val += MOD;
    }
    constexpr int getmod() { return MOD; }
    constexpr Fp operator - () const noexcept {
        return val ? MOD - val : 0;
    }
    constexpr Fp operator + (const Fp& r) const noexcept { return Fp(*this) += r; }
    constexpr Fp operator - (const Fp& r) const noexcept { return Fp(*this) -= r; }
    constexpr Fp operator * (const Fp& r) const noexcept { return Fp(*this) *= r; }
    constexpr Fp operator / (const Fp& r) const noexcept { return Fp(*this) /= r; }
    constexpr Fp& operator += (const Fp& r) noexcept {
        val += r.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    constexpr Fp& operator -= (const Fp& r) noexcept {
        val -= r.val;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr Fp& operator *= (const Fp& r) noexcept {
        val = val * r.val % MOD;
        return *this;
    }
    constexpr Fp& operator /= (const Fp& r) noexcept {
        long long a = r.val, b = MOD, u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b; swap(a, b);
            u -= t * v; swap(u, v);
        }
        val = val * u % MOD;
        if (val < 0) val += MOD;
        return *this;
    }
    constexpr bool operator == (const Fp& r) const noexcept {
        return this->val == r.val;
    }
    constexpr bool operator != (const Fp& r) const noexcept {
        return this->val != r.val;
    }
    friend constexpr ostream& operator << (ostream &os, const Fp<MOD>& x) noexcept {
        return os << x.val;
    }
    friend constexpr Fp<MOD> modpow(const Fp<MOD> &a, long long n) noexcept {
        if (n == 0) return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1) t = t * a;
        return t;
    }
};
template<size_t t> using mint = Fp<t>;
ll gcd(ll a, ll b) { return b?gcd(b,a%b):a; } // 最大公約数
ll lcm(ll a, ll b) { return a/gcd(a,b)*b; } // 最小公倍数
void Yes(bool f = 1) { cout<<(f ? "Yes" : "No")<<endl; }
void No(bool f = 1) { Yes(!f); }

constexpr ll INFd = (1LL << 60);

struct Edge{ // 辺の情報
	ll to; // 行先
	ll cost; // コスト
};
using Graph = vvc<Edge>;
using Pair = pair<ll, int>; // { distance, from }

// ダイクストラ法 (基本実装)
// distances は頂点数と同じサイズ, 全要素 INFd で初期化しておく
void Dijkstra(const Graph& graph, vc<ll>& distances, int startIndex){
	// 「現時点での最短距離, 頂点」の順に取り出す priority_queue
	// デフォルトの priority_queue は降順に取り出すため std::greater を使う
	pqg<Pair> q;
	q.emplace((distances[startIndex] = 0), startIndex);

	while (!q.empty()){
		const long long distance = q.top().first;
		const int from = q.top().second;
		q.pop();

		// 最短距離でなければ処理しない
		if (distances[from] < distance){
			continue;
		}

		// 現在の頂点からの各辺について
		for (const auto& edge : graph[from]){
			// to までの新しい距離
			const long long d = (distances[from] + edge.cost);

			// d が現在の記録より小さければ更新
			if (d < distances[edge.to]){
				q.emplace((distances[edge.to] = d), edge.to);
			}
		}
	}
}

// 重みつき有効グラフ，最短経路問題，ダイクストラ法
void solve(){
  ll n;
  cin>>n;
  Graph g(n);
  REP(i,n-1){
    ll a,b,x;
    cin>>a>>b>>x;
    x--;
    g[i].push_back({i+1,a});
    if(i!=x)g[i].push_back({x,b});
  }
  vc<ll> dis(n,INFd);
  Dijkstra(g,dis,0);
  cout<<dis[n-1]<<endl;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(20);
    int t=1;
    // cin >> t;
    while(t--)solve();
    return 0;
}