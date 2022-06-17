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
vector<int> son;
vector<int> dist;
int dfs(int v) {
	int maxi = v == N;
	/*if (adj[v].size() == 0)
		maxi = v == N;*/
	for (int u : adj[v]) {
		int val;// = dfs(u);
		if (dist[u] != -1)
			val = dist[u];
		else
			val = dfs(u);
		if (maxi <= val && val > 0) {
			son[v] = u;
			maxi = val + 1;
		}
	}
	dist[v] = maxi;
	return maxi;
}

int main()
{
	cin >> N >> M;
	adj.resize(N + 1, vector<int>());
	son.resize(N + 1);
	dist.resize(N + 1,-1);
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
	}
	int val = dfs(1);
	if (val == 0) {
		cout << "IMPOSSIBLE";
		return 0;
	}
	cout << val << '\n';
	for (int v = 1;; v = son[v]) {
		cout << v << ' ';
		if (v == N)break;
	}
}