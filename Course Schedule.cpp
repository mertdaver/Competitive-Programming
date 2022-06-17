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
vector<int> ord;
vector<bool> done;
vector<bool> seen;

bool cyclic(int v) {
    if (done[v]) {
        return true;
    }
    done[v] = 1;
    for (int u : adj[v]) {
        if (seen[u])continue;
        if (cyclic(u))return true;
    }
    done[v] = 0;
    seen[v] = 1;
    return false;
}

void dfs(int v) {
    done[v] = 1;
    for (int u : adj[v]) {
        if (done[u])continue;
        dfs(u);
    }
    ord.push_back(v);
}

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    adj.resize(N + 1, vector<int>());
    done.resize(N + 1);
    seen.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= N; i++) {
        if (!seen[i] && cyclic(i)) {
            cout << "IMPOSSIBLE";
            return 0;
        }
    }
    done.assign(N + 1, 0);
    for (int i = 1; i <= N;i++) {
        if (!done[i]){
            dfs(i);
        }
    }
    reverse(ord.begin(), ord.end());
    for (int i = 0; i < ord.size(); i++) {
        cout << ord[i] << " ";
    }
}
