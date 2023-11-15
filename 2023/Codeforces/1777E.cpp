#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
#define PI pair<int,int>
#define PII pair<int,pair<int,bool>>



int N, M, T;
vector<vector<PII>> adj;
//vector<vector<PII>> adj_rev;
vector<bool> visited;
vector<int> ord;
vector<vector<int>> comps; //A set of all sccs.
vector<int> comp;

void TopologicalSort(int v, int w) {
    visited[v] = 1;
    for (auto pp : adj[v]) {
        if (visited[pp.first] || pp.second.first <= w || pp.second.second) continue;
        TopologicalSort(pp.first, w);
    }
    ord.push_back(v);
}

void dfs0(int v, int w) { //dfs on subgraph G^ where all weights are smaller (not strictly) than w. basiclly it's a undirected graph.
    visited[v] = 1;
    for (auto pp : adj[v]) {
        if (visited[pp.first] || pp.second.first > w) continue;
        dfs0(pp.first, w);
    }
}

void dfs1(int v, int w) { //dfs on G transpose.
    visited[v] = 1;
    comp.push_back(v);
    for (auto pp : adj[v]) {
        if (visited[pp.first] || pp.second.first <= w || pp.second.first) continue;
        dfs1(pp.first, w);
    }
}

vector<int> SCC(int w) {
    vector<int> answer(N);
    for (int i = 0; i < N; i++) {
        if (!visited[i]) TopologicalSort(i, w);
    }
    visited.assign(N, 0);
    int cnt = 0; //scc's index
    reverse(ord.begin(), ord.end());
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            dfs1(i, w); 
            comps.push_back(comp);
            for (int node : comp) {
                answer[node] = cnt;
            }
            cnt++;
            comp.clear();
        }
    }
    visited.assign(N, 0);
    return answer;
}

bool good(int w) {
    vector<int> group = SCC(w); //return an array where group[i] is the scc i belongs to.
    dfs0(ord[0], w); //dfs on G' where G'is the subgraph where all edges are of weight smaller (not strictly) than w.
    visited.assign(N, 0);
    vector<bool> groupSeen(comps.size());

    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            groupSeen[group[i]] = true;
        }
    }

    for (int i = 0; i < comps.size(); i++) {
        if (!groupSeen[i]) return false;
    }
    return true;
}

void solve() {
    cin >> N >> M;
    adj.resize(N,vector<PII>());
    visited.resize(N, 0);

    int l = 0;
    int r = 0;
    int tempMax = 0;
    
    for (int i = 0; i < M; i++) {
        int u, v, w; cin >> u >> v >> w;
        u--; v--;
        adj[u].push_back({ v,{w,0} });
        adj[v].push_back({ u,{w,1} });
        r = max(r,w);
    }
    tempMax = r;

    int w = (l + r) / 2;
    int sol = r;

    while (l <= r) {
        if (w == 20) {
            int asd = 0;
        }
        if (good(w)) {
            sol = w;
            r = w - 1;
        }
        else {
            l = w + 1;
        }
        w = (l + r) / 2;
    }
    if (l == tempMax + 1) {
        sol = -1;
    }

    cout << sol << '\n';
    adj.clear();
    visited.clear();
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> T;
    while (T--) {
        solve();
    }
}
