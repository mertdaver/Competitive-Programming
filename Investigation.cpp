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
vector<vector<pair<int, int>>> adj;
vector<ll> ways,fast,slow,d;
ll mini;

void Dijkstra(vector<bool>& done) {
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({ 0,1 });
    while (!pq.empty()) {
        int v = pq.top().second; pq.pop();
        if (done[v])continue;
        done[v] = 1;
        for (pair<int, int> p : adj[v]) {
            int u = p.second; ll w = p.first;
            if (d[u] >= d[v] + w) {
                d[u] = d[v] + w;
                pq.push({d[u], u});
            }
        }
    }
}
void dfs(int v, ll price, int par) {
    if (v == N) {
        ways[par]++;
        fast[par] = 1;
        if (!slow[par])slow[par] = 1;
        return;
    }
    for (pair<int, int> p : adj[v]) {
        int u = p.second, w = p.first;
        if (d[u] == d[v] + w) {
            if(ways[u] == 0)dfs(u, price + w,v);
            if (ways[u] != 0) {
                ways[v] += ways[u] % MOD;
                fast[v] = min(fast[v], fast[u] + 1);
                slow[v] = max(slow[v], slow[u] + 1);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    adj.resize(N + 1, vector<pair<int,int>>());
    ways.resize(N + 1, 0);
    fast.resize(N + 1, INF); slow.resize(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({ c,b });
    }
    d.resize(N + 1, INF);
    vector<bool> done(N + 1);
    d[1] = 0;
    Dijkstra(done);
    mini = d[N];
    dfs(1,0,1);
    cout << mini << " " << ways[1] << " " << fast[1] << " " << slow[1];
}




/*ways[v] = max(0,ways[v]);
for (pair<int, int> p : adj[v]) {
    int u = p.second, w = p.first;
    if (u == N) {
        if (price + w == mini) {
            ways[v]++; ways[v] %= MOD;
            fast[v] = min(fast[v], (ll)1);
            slow[v] = max(slow[v], (ll)1);
            continue;
        }
    }
    if (ways[u] == -1) {
        dfs(u, price + w);
    }
    ways[v] += ways[u] % MOD;
    if (ways[u]) {
        slow[v] = max(slow[v], slow[u] + 1);
        fast[v] = min(fast[v], fast[u] + 1);
    }
}*/