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

int main()
{
    fast;
    cin >> N;
    vector<bool> done(N + 1);
    queue<int> q;
    adj.resize(N + 1, vector<int>()); deg.resize(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int a, b; cin >> a >> b;
        deg[a]++; deg[b]++;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= N; i++) {
        if (deg[i] == 1)q.push(i);
    }
    int ans = 0;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        bool flag = false;
        done[v] = 1;
        for (int u : adj[v]) {
            if (done[u])continue;
            if (!flag) {
                flag = true;
                ++ans;
            }
            done[u] = 1;
            for (int w : adj[u]) {
                if (done[w])continue;
                deg[w]--;
                if (deg[w] == 1) {
                    q.push(w);
                }
            }
        }
    }
    cout << ans;
}
