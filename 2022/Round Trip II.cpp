#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;
typedef long long ll;
const ll INF = 1e18;
int N, M;
vector<vector<int>> adj;
vector<int> cyc;
vector<int> par;

bool dfs(int v, vector<bool>& done, int p, vector<bool>& seen) {
    par[v] = p;
    if (done[v]) {
        for (int u = v;; u = par[u]) {
            cyc.push_back(u);
            if (par[u] == v)break;
        }
        cyc.push_back(v);
        return true;
    }
    done[v] = 1;
    for (int u : adj[v]) {
        if (seen[u])continue;
        if(dfs(u, done, v,seen))return true;
    }
    done[v] = 0;
    seen[v] = 1;
    return false;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    adj.resize(N + 1, vector<int>());
    par.resize(N + 1,-1);
    vector<bool> done(N + 1, 0);
    vector<bool> seen(N + 1, 0);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= N; i++) {
        if (!seen[i] && dfs(i, done, -1,seen)) {
            reverse(cyc.begin(), cyc.end());
            cout << cyc.size() << '\n';
            for (int j = 0; j < cyc.size(); j++) {
                cout << cyc[j] << " ";
            }
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}
