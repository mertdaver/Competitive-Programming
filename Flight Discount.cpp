#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;
typedef long long ll;
const ll INF = 1e18;
vector<vector<pair<ll, ll>>> adj;
vector<vector<pair<ll, ll>>> Gr;

void Dijkstra(int src, vector<ll>& d, vector<bool> done) {
    d[src] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({ 0,src });
    while (!pq.empty()){
        int v = pq.top().second; 
        pq.pop();
        if (done[v])continue;
        done[v] = 1;
        for (pair<ll, ll> p : adj[v]) {
            int u = p.second;
            if (d[u] > d[v] + p.first) {
                d[u] = d[v] + p.first;
                pq.push({ d[u],u });
            }
        }
    }
}

void DijkstraGr(int src, vector<ll>& d, vector<bool> done) {
    d[src] = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({ 0,src });
    while (!pq.empty()) {
        int v = pq.top().second;
        pq.pop();
        if (done[v])continue;
        done[v] = 1;
        for (pair<ll, ll> p : Gr[v]) {
            int u = p.second;
            if (d[u] > d[v] + p.first) {
                d[u] = d[v] + p.first;
                pq.push({ d[u],u });
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M; cin >> N >> M;
    adj.resize(N + 1, vector<pair<ll, ll>>());
    Gr.resize(N + 1, vector<pair<ll, ll>>());
    vector<tuple<ll, ll, ll>> edges(M);
    vector<bool> done(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ c,b });
        Gr[b].push_back({ c,a });
        edges[i] = { a,b,c };
    }
    vector<ll> d1(N+1,INF);
    vector<ll> d2(N+1,INF);
    Dijkstra(1, d1, done);
    done.assign(N + 1, 0);
    DijkstraGr(N, d2, done);
    ll ans = d1[N];
    for (int i = 0; i < M; i++) {
        int a, b, c; tie(a, b, c) = edges[i];
        ans = min(d1[a] + d2[b] + ll(c / 2), ans);
    }
    cout << ans;
}
