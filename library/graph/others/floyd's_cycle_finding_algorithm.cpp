#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<class t> using vc = vector<t>;

// フロイドの循環検出法
// Floyd's cycle-finding algorithm
// ループの最初の最後の値，最初の値，ループ長さを返す
// O(N)
tuple<ll, ll, ll> FloydsCycleFinding(const vc<ll> &nums) {
    ll hare = 0, tortoise = 0;
    while (true) {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
        if (tortoise == hare) break;
    }
    ll m = tortoise;
    hare = 0;
    while (tortoise != hare) {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }
    ll l = hare;
    ll u = 0;
    while (true) {
        u += 1;
        hare = nums[hare];
        hare = nums[hare];
        if (tortoise == hare) break;
    }
    return forward_as_tuple(m, l, u);
}
