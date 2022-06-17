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
vector<vector<int>> adj;
vector<int> deg;
vector<int> ht;
vector<int> dist;

int dfs1(int v, int p) {
    int h = 0;
    for (int u : adj[v]) {
        if (u == p)continue;
        h = max(h, dfs1(u, v));
    }
    ht[v] = h;
    return h+1;
}

void dfs2(int v,int p, int last, bool flag) { //last - father's max dist from another subtree, flag - i'm in my father's dist
    ++last; // <-- update last
    int maxi1 = 0, maxi2 = 0, idx = 0;
    for (int u : adj[v]) {
        if (u == p)continue;
        if (ht[u] > maxi1) {
            maxi2 = maxi1;
            maxi1 = ht[u];
            idx = u;
            continue;
        }
        if (ht[u] > maxi2) {
            maxi2 = ht[u];
            continue;
        }
    }
    maxi1++;maxi2++;
    if (!flag) {
        dist[v] = dist[p] + 1;
    }
    else {
        dist[v] = max(last, maxi1);
    }
    if (maxi1 <= last)idx = 0;
    maxi2 = max(maxi2, last);
    for (int u : adj[v]) {
        if (u == p)continue;
        if (u == idx) {
            dfs2(u, v, maxi2, true);
        }
        else {
            dfs2(u, v, max(maxi1, last), false);
        }
    }
}

int main()
{
    fast;
    cin >> N;
    adj.resize(N + 1, vector<int>());
    deg.resize(N + 1);
    ht.resize(N + 1);
    dist.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        deg[a]++; deg[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int root = 0, last = 0;
    for (int i = 1;i <= N;i++) {
        if (deg[i] > last) {
            last = deg[i];
            root = i;
        }
    }
    dfs1(root, -1);
    dfs2(root, 0, -1, true);
    if (N == 2) {
        dist[1] = dist[2] = 1;
    }
    for (int i = 1;i < N;i++) {
        cout << dist[i] << " ";
    }
    cout << dist[N];
}
