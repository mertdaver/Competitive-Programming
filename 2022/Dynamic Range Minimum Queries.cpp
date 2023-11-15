#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;
typedef long long ll;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;
int N, Q;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> Q;
    int root = sqrt(N);
    vector<int> block(N + 1);
    vector<int> v(N + 1);
    vector<int> roots(N / root + 1,INF);
    for (int i = 1; i <= N; i++) {
        cin >> v[i];
        block[i] = (i - 1) / root;
        roots[block[i]] = min(roots[block[i]], v[i]);
    }
    while (Q--) {
        int type; cin >> type;
        if (type == 2) {
            int l, r; cin >> l >> r;
            int ans = INF;
            while (r > l && r % root) {
                ans = min(ans, v[r]);
                --r;
            }
            while (l < r && (l - 1) % root) {
                ans = min(ans, v[l]);
                ++l;
            }
            while (block[l] < block[r]) {
                ans = min(ans, roots[block[r]]);
                r -= root;
            }
            while (l <= r) {
                ans = min(ans, v[l]); l++;
            }
            cout << ans << '\n';
        }
        else {
            int k, u; cin >> k >> u;
            roots[block[k]] = INF;
            v[k] = u;
            for (int i = (block[k]) * root + 1; i <= N && block[i] == block[k]; i++) {
                roots[block[k]] = min(roots[block[k]], v[i]);
            }
        }
    }
}
