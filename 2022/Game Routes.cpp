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
int N, M;
vector<vector<int>> adj;
vector<ll> cnt;
ll dfs(int v) {
    ll ans = v == N;
    for (int u : adj[v]) {
        if (cnt[u] == -1)
            cnt[u] = dfs(u) % MOD;
        ans += cnt[u];
    }
    return ans % MOD;
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    adj.resize(N + 1, vector<int>());
    cnt.resize(N + 1, -1);
    cnt[N] = 1;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    cout << dfs(1) % MOD;
}
