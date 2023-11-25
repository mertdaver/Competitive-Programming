#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
#define PI pair<int,int>

vector<vector<int>> adj;
ll dp[(int)1e5 + 5];

void dfs(int v, int par) {
    ll xored = 0;
    for (int u : adj[v]) {
        if (u == par)continue;
        dfs(u, v);
        xored ^= (dp[u]+1);
    }

    dp[v] = xored;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    adj.resize(N, vector<int>());

    for (int i = 0; i < N - 1; i++) {
        int x, y; cin >> x >> y; --x; --y;
        adj[x].push_back(y);
        adj[y].push_back(x); 
    }
    dfs(0,0);
    if (dp[0]) {
        cout << "Alice";
    }
    else {
        cout << "Bob";
    }
}
