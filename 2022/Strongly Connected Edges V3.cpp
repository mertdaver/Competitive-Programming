#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <stack>
#include <set>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
int N, M;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define loop(x, n) for(int x = 0; x < n; ++ x)
#define PB push_back
vector<vector<int>> adj;
vector<bool> visited;
vector<bool> used;
vector<int> tin, low;
set<pair<int,int>> s;
int timer;
bool flag = false;

void dfs0(int v) {
    if (used[v]) return;
    used[v] = 1;
    for (int u : adj[v])dfs0(u);
}

void dfs1(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        }
        else {
            dfs1(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])flag = 1;
        }
    }
}

void dfs2(int v, int p) {
    if (p != -1) {
        if (s.count({ v,p }))return;
        s.insert({ v,p });
        s.insert({ p,v });
        cout << p + 1 << " " << v + 1 << '\n';
        if (used[v])return;
    }
    used[v] = 1;
    for (int u : adj[v]) {
        if (u == p)continue;
        dfs2(u, v);
    }
}

int main()
{
    fast;
    cin >> N >> M;
    timer = 0;
    visited.assign(N, false);
    tin.assign(N, -1);
    low.assign(N, -1);
    adj.resize(N, vector<int>());
    used.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; --a;--b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    dfs0(0);
    for (int i = 0; i < N; ++i) {
        if (!used[i]) { cout << "IMPOSSIBLE"; return 0; }
    }
    for (int i = 0; i < N; ++i) {
        if (!visited[i])dfs1(i);
    }
    if (flag) { cout << "IMPOSSIBLE"; return 0; }
    used.assign(N,0);
    dfs2(0,-1);
}
