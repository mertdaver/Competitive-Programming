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
int N;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define loop(x, n) for(int x = 0; x < n; ++ x)
#define PB push_back

vector<vector<int>> adj;
vector<ll> sz;
vector<ll> dist;
vector <ll> sum;

ll dfs1(int v, int p) {
    for (int u : adj[v]) {
        if (u == p)continue;
        sz[v] += dfs1(u, v);
    }
    return sz[v];
}
ll dfs2(int v, int p) {
    for (int u : adj[v]) {
        if (u == p)continue;
        dist[v] += dfs2(u,v) + sz[u];
    }
    return dist[v];
}
void dfs3(int v, int p, ll si) {
    sum[v] = sum[p] + si - sz[v];
    for (int u : adj[v]) {
        if (u == p)continue;
        si += sz[u];
    }
    for (int u : adj[v]) {
        if (u == p)continue;
        dfs3(u, v, si - sz[u] + 1);
    }
}

int main()
{
    fast;
    cin >> N;
    adj.resize(N + 1, vector<int>());
    sz.resize(N + 1,1);
    dist.resize(N + 1);
    sum.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    int root = 0, last = 0;
    for (int i = 1;i <= N;i++) {
        if (adj[i].size() > last) {
            last = adj[i].size();
            root = i;
        }
    }
    dfs1(root,0);
    dfs2(root, 0);
    sum[root] = dist[root];
    for (int u : adj[root]) {
        dfs3(u, root, sz[root] - sz[u]);
    }
    if (N == 2) {
        sum[1] = sum[2] = 1;
    }
    for (int i = 1;i <= N;i++) {
        cout << sum[i] << " ";
    }
}
