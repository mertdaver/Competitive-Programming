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
vector<int> dist;
vector<vector<int>> son;
int dfs(int v) {
    //if (done[v])return -1;
    //done[v] = 1;
    int ans = 0;
    for (int u : son[v]) {
        ans += dfs(u) + 1;
    }
    dist[v] = ans;
    return ans;
}

int main()
{
    fast;
    cin >> N;
    son.resize(N + 1, vector<int>());
    dist.resize(N + 1);
    for (int i = 2; i <= N; i++) {
        int p; cin >> p;
        son[p].push_back(i);
    }
    dfs(1);
    for (int i = 1;i <= N;i++) {
        cout << dist[i] << " ";
    }
}
