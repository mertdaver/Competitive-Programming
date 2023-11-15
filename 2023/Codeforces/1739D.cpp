#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
vector<vector<int>> adj;
vector<int> ord;
vector<int> depth;
vector<vector<int>> ancestor;
vector<bool> visited;

void dfs(int v) {
    visited[v] = 1;
    for (int u : adj[v]) {
        if (visited[u])continue;
        dfs(u);
    }
}

void bfs(int v) {
    depth[v] = 0;
    queue<int> q; q.push(v);
    while (!q.empty()) {
        int v = q.front(); q.pop(); ord.push_back(v);
        for (int u : adj[v]) {
            depth[u] = depth[v] + 1;
            q.push(u);
        }
    }
}

int hAncestor(int v,int h) { //technically, h-1 ancestor ;)
    int times = 0;
    while (h) {
        if (h % 2) {
            v = ancestor[v][times];
        }
        h /= 2;
        times++;
    }
    return v;
}

bool good(int h) { //h is good iff every node of depth bigger than h has been visited -  need to repair that.
    if (h == 1) {
        int num = 0;
        for (int i = 0; i < n; i++)num += depth[i] > h;
        return num <= k;
    }
    int kTemp = k;
    int i = 0;
    while (!visited[0] && kTemp>=0) {
        while (visited[ord[i]]) {
            i++;
        }
        if (kTemp) { dfs(hAncestor(ord[i], h - 1)); kTemp--; }
        else break;
    }

    for (int i = 0; i < n; i++) {
        if (!visited[i] && depth[i] > h)return false;
    }

    return true;
}

void solve() {
    cin >> n >> k;
    adj.resize(n,vector<int>());
    depth.resize(n, 0);
    ancestor.resize(n, vector<int>(24));
    visited.resize(n, 0);
    
    for (int i = 1; i < n; i++) {
        int par; cin >> par; --par;
        adj[par].push_back(i); ancestor[i][0] = par;
    }

    for (int j = 1; j < 24; j++) {
        for (int i = 0; i < n; i++) {
            ancestor[i][j] = ancestor[ancestor[i][j - 1]][j - 1];
        }
    }
    bfs(0);
    reverse(ord.begin(), ord.end());
    int l = 1; int r = n - 1; int target = (l + r) / 2; int cand = r;


    while (l <= r) {
        if (good(target)) {
            cand = target;
            r = target - 1;
        }
        else {
            l = target + 1;
        }
        target = (l + r) / 2;
        visited.assign(n, 0);
    }

    cout << cand << '\n';
    adj.clear(); ord.clear(); ancestor.clear(); depth.clear(); visited.clear();
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
