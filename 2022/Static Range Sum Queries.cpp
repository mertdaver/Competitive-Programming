#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int N, Q; cin >> N >> Q;
    vector <ll> pref(N + 1);
    vector<ll> v(N + 1);
    for (int i = 1; i <= N; i++) {
        ll x; cin >> x;
        pref[i] = pref[i - 1] + x;
        v[i] = x;
    }
    while (Q--) {
        int i, j; cin >> i >> j;
        if (i < j)swap(i, j);
        cout << pref[i] - pref[j] + v[j] << '\n';
    }
}
