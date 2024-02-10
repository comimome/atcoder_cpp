#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    ll to;
    ll weight;
    Edge(ll t, ll w) : to(t), weight(w) { }
};