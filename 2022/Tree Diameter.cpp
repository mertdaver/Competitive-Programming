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
vector<int> ht;
vector<vector<int>> adj;
vector<bool> done;
void dfs(int v,int h) {
    done[v] = 1;
    ht[v] = h;
    for (int u : adj[v]) {
        if (done[u])continue;
        done[u] = 1;
        dfs(u, h + 1);
    }
}

int main()
{
    fast;
    cin >> N;
    ht.resize(N + 1);
    adj.resize(N + 1,vector<int>());
    done.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, 0);
    int v, last = 0;
    for (int i = 1; i <= N; i++) {
        if (ht[i] > last) {
            v = i;
            last = ht[i];
        }
    }
    done.assign(N + 1, 0);
    ht.assign(N + 1, 0);
    dfs(v, 0);
    int maxi = 0;
    for (int i = 1; i <= N;i++) {
        maxi = max(maxi, ht[i]);
    }
    cout << maxi;
}
