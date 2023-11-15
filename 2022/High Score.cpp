#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;
typedef long long ll;
const ll INF = -1e18;
void bfs(vector<vector<ll>>& Gr, int N, vector<bool>& seen) {
    queue<ll> q; q.push(N);
    seen[N] = 1;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        for (int u : Gr[v]) {
            if (seen[u])continue;
            seen[u] = 1;
            q.push(u);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    vector<tuple<ll,ll,ll>> edges(M + 1);
    vector<vector<ll>> Gr(N + 1, vector<ll>());
    vector<bool> seen(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[i] = { a,b,c };
        Gr[b].push_back(a);
    }
    bfs(Gr,N,seen);
    vector<ll> dist(N + 1,INF);
    dist[1] = 0;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < M; j++) {
            int a, b, c; tie(a, b, c) = edges[j];
            if (dist[a] != INF) {
                dist[b] = max(dist[a] + c, dist[b]);
            }
        }
    }
    ll ans = dist[N];
    for (int j = 0; j < M; j++) {
        int a, b, c; tie(a, b, c) = edges[j];
        ll tmp = dist[b];
        if (dist[a] != INF) {
            dist[b] = max(dist[a] + c, dist[b]);
        }
        if (dist[b] != tmp && seen[b]) {
            ans = -1;
            break;
        }
    }
    if (ans != dist[N]) { ans = -1; }
    cout << ans;
}
