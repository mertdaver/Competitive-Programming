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
int N, Q;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    int root = sqrt(N);
    vector<int> block(N + 1);
    vector<int> v(N + 1);
    vector<ll> roots(N / root + 1);
    ll sum = 0;
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        block[i] = (i-1) / root;
        roots[block[i]] += v[i];
    }
    while (Q--) {
        int type; cin >> type;
        if (type == 2) {
            int l, r; cin >> l >> r;
            ll ans = 0;
            while (r > l && r % root) {
                ans += v[r--];
            }
            while (l < r && (l-1) % root){
                ans += v[l++];
            }
            while (block[l] < block[r]) {
                ans += roots[block[r]];
                r-=root;
            }
            while (l <= r) { ans += v[l++]; }
            cout << ans << '\n';
        }
        else {
            int k, u; cin >> k >> u;
            roots[block[k]] -= v[k];
            v[k] = u;
            roots[block[k]] += u;
        }
    }
}
