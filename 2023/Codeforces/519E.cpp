#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;
#define PI pair<int,int>

vector<int> sz;
vector<vector<int>> ancestors;
vector<vector<int>> adj;
vector<int> depth;
vector<int> tin, tout;

int n, q, root, timer;

int kJump(int v, int k) {
    int i = 0;
    while (k) {
        if (k % 2) {
            v = ancestors[v][i];
        }
        k /= 2;
        i++;
    }
    return v;
}

bool is_ancestor(int u, int v) {
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int v, int u) {
    if (is_ancestor(v, u))
        return v;
    if (is_ancestor(u, v))
        return u;
    for (int i = 31; i >= 0; --i) {
        if (!is_ancestor(ancestors[v][i], u))
            v = ancestors[v][i];
    }
    return ancestors[v][0];
}

void dfs0(int v, int par,int dep) {
    tin[v] = ++timer;
    depth[v] = dep;
    ancestors[v][0] = par;
    for(int u : adj[v]){
        if (u == par) continue;
        dfs0(u, v, dep+1);
        sz[v] += sz[u];
    }
    tout[v] = ++timer;
}

void ancestorsInit() {
    dfs0(root, root,0);
    for (int j = 1; j < 32; j++) {
        for (int i = 0; i < n; i++) {
            ancestors[i][j] = ancestors[ancestors[i][j - 1]][j - 1];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    sz.resize(n, 1);
    ancestors.resize(n, vector<int>(32));
    adj.resize(n, vector<int>());
    depth.resize(n, 0);
    tin.resize(n, 0); tout.resize(n, 0);

    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++) {
        if (adj[i].size() > 1) { 
            root = i; 
            break; 
        }
    }
    ancestorsInit();
    cin >> q;
    while (q--) {
        int a, b; cin >> a >> b;
        a--; b--;
        if (depth[a] % 2 != depth[b] % 2) {
            cout << 0 << '\n';
            continue;
        }
        if (a == b) {
            cout << sz[root] << '\n';
            continue;
        }
        if (depth[a] == depth[b]) {
            int w = lca(a, b);
            int aAncestor = kJump(a, depth[a] - depth[w] - 1);
            int bAncestor = kJump(b, depth[b] - depth[w] - 1);
            int sol = sz[root] - sz[aAncestor] - sz[bAncestor];
            cout << sol << '\n';
            continue;
        }
        if (depth[a] < depth[b]) swap(a, b);
        //depth[a] > depth[b], depth[a] mod 2 = depth[b] mod 2

        int w = lca(a, b);
        int diff = (depth[a] - depth[b]) / 2;
        int dist = depth[a] - depth[w] - diff;

        int target = kJump(a, dist);
        int aAncestor = kJump(a, dist - 1);
        int sol = sz[target] - sz[aAncestor];
        cout << sol << '\n';
    }
}
