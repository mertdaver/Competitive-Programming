#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <stack>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
int N,M;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define loop(x, n) for(int x = 0; x < n; ++ x)
#define PB push_back

vector<vector<int>> adj;

int bfs(int src) {
    int ans = INF;
    queue<pair<int, int>> q; q.push({src,-1});
    vector<int> dist(N + 1, INF);
    dist[src] = 0;
    while (!q.empty()) {
        auto ii = q.front();q.pop();int v = ii.first, p = ii.second;
        for (int u : adj[v]) {
            if (u == p)continue;
            if (dist[u] != INF) {
                ans = min(ans, dist[v] + dist[u] + 1);
                continue;
            }
            dist[u] = dist[v] + 1;
            q.push({ u,v });
        }
    }
    return ans;
}

int main()
{
    fast;
    cin >> N >> M;
    adj.resize(N + 1, vector<int>());
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    int mini = INF;
    for (int i = 1;i <= N;i++)mini = min(mini, bfs(i));
    if (mini == INF) { cout << -1;return 0; }
    cout << mini;
}
