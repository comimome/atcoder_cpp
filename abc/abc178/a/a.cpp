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

void solve(){
    int x;
    cin>>x;
    if(x==0)cout<<1<<endl;
    else cout<<0<<endl;
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