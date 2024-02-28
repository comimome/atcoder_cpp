#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define FOR(i, m, n) for (ll i = (m); i <= (n); ++i)
#define FORR(i, m, n) for (ll i = (m); i >= (n); --i)
#define REP(i, n) for (ll i = 0; i < (n); ++i)
#define REPR(i, n) for (ll i = (n); i >= 0; --i)
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

// 進数変換
// n 進 10 進変換
int ntodec(const char c){
    switch(c){
        case '0': return 0;
        case '1': return 1;
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'A': return 10;
        case 'B': return 11;
        case 'C': return 12;
        case 'D': return 13;
        case 'E': return 14;
        case 'F': return 15;
        case 'G': return 16;
        case 'H': return 17;
        case 'I': return 18;
        case 'J': return 19;
        case 'K': return 20;
        case 'L': return 21;
        case 'M': return 22;
        case 'N': return 23;
        case 'O': return 24;
        case 'P': return 25;
        case 'Q': return 26;
        case 'R': return 27;
        case 'S': return 28;
        case 'T': return 29;
        case 'U': return 30;
        case 'V': return 31;
        case 'W': return 32;
        case 'X': return 33;
        case 'Y': return 34;
        case 'Z': return 35;
        default : return -1;
    }
}

// 10 進 n 進変換
char decton(const int n){
    switch(n){
        case 0: return '0';
        case 1: return '1';
        case 2: return '2';
        case 3: return '3';
        case 4: return '4';
        case 5: return '5';
        case 6: return '6';
        case 7: return '7';
        case 8: return '8';
        case 9: return '9';
        case 10: return 'A';
        case 11: return 'B';
        case 12: return 'C';
        case 13: return 'D';
        case 14: return 'E';
        case 15: return 'F';
        case 16: return 'G';
        case 17: return 'H';
        case 18: return 'I';
        case 19: return 'J';
        case 20: return 'K';
        case 21: return 'L';
        case 22: return 'M';
        case 23: return 'N';
        case 24: return 'O';
        case 25: return 'P';
        case 26: return 'Q';
        case 27: return 'R';
        case 28: return 'S';
        case 29: return 'T';
        case 30: return 'U';
        case 31: return 'V';
        case 32: return 'W';
        case 33: return 'X';
        case 34: return 'W';
        case 35: return 'Z';
        default : return '\0';
    }
}

// べき乗計算
inline ll pow_ll(ll x, ll n){
    ll ret = x;
    if(n==0) return 1;
    for(ll i=1; i<n; i++){
        ret *= x;
    }
    return ret;
}

// n 進数で表現された数値を文字列 str で受け取り、m 進数に直して文字列で出力する
string n_ary(string str, int n, int m){
  unsigned long tmp = 0;
  string ret;
  for(int i=0; i<str.length(); i++){
    tmp += (unsigned long) ntodec(str[str.length()-1-i]) * pow_ll(n, i);
  }
  if(tmp==0) return "0";
  while(tmp!=0){
    ret = decton(tmp%m) + ret;
    tmp/=m;
  }
  return ret;
}

void solve(){
    int n,m;
    cin>>n>>m;
    vc<string> s(n);
    REP(i,n)cin>>s[i];
    ll k=0,g=0;
    REP(i,n){
        int sum=0;
        REP(j,m){
            if(s[i][j]=='1')sum++;
        }
        if(sum%2==0)g++;
        else k++;
    }
    cout<<g*k<<endl;
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