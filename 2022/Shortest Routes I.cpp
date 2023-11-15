#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
ll INF = 1e18;

vector<vector<pair<int, int>>> adj;

void Dijkstra(int v, vector<ll>& d, vector<bool>& done) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({ 0,v });
    while (!pq.empty()) {
        ll u = pq.top().second;
        pq.pop();
        if (done[u])continue;
        done[u] = 1;
        for (pair<ll, ll> p : adj[u]) {
            ll w = p.first;
            if (d[w] > d[u] + p.second) {
                d[w] = d[u] + p.second;
                pq.push({ d[w],w });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    adj.resize(N + 1, vector<pair<int, int>>());
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ b,c });
    }
    vector<ll> dist(N + 1,INF);
    dist[1] = 0;
    vector<bool> done(N + 1);
    Dijkstra(1, dist,done);
    for (int i = 1; i <= N; i++) {
        cout << dist[i] << " ";
    }
}
