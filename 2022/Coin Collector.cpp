#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;
typedef long long ll;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
int N, M;
vector<vector<int>> adj;
vector<vector<int>> Gt;
vector<int> ord;
vector<bool> done;
vector<int> comps;
vector<ll> d;

void dfs1(int v) {
	if (done[v])return;
	done[v] = 1;
	for (int u : adj[v])
		dfs1(u);
	ord.push_back(v);
}
void dfs2(int v) {
	if (done[v])return;
	done[v] = 1;
	comps.push_back(v);
	for (int u : Gt[v]) {
		dfs2(u);
	}
}

ll dfs3(int v, vector<vector<int>>& adj_scc, vector<ll>& prof) {
	if (done[v])return d[v];
	done[v] = 1;
	ll ans = prof[v];
	for (int u : adj_scc[v])
		ans = max(dfs3(u, adj_scc,prof) + prof[v],ans);
	d[v] = ans;
	return ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	vector<int> K(N + 1);
	adj.resize(N + 1, vector<int>());
	Gt.resize(N + 1, vector<int>());
	d.resize(N + 1, 0);
	done.resize(N + 1);
	for (int i = 1; i <= N; i++)
		cin >> K[i];
	for (int i = 0; i < M; i++) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		Gt[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
		dfs1(i);
	done.assign(N + 1, 0);
	vector<int> roots(N+1,0);
	vector<ll> prof(N+1,0);
	vector<int> leaders;
	reverse(ord.begin(), ord.end());
	for (int vertex : ord) {
		if (done[vertex])continue;
		dfs2(vertex);
		int root = comps.front();
		ll price = 0;
		for (int u : comps) {
			roots[u] = root;
			price += K[u]; 
		}
		leaders.push_back(root);
		prof[root] = price;
		comps.clear();
	}
	vector<vector<int>> adj_scc(N+1);
	for (int i = 1; i <= N; i++) {
		for (int u : adj[i]) {
			if (roots[i] != roots[u])
				adj_scc[roots[i]].push_back(roots[u]);
		}
	}
	ll maxi = 0;
	done.assign(N + 1, 0);
	for (int vertex : leaders) {
		maxi = max(maxi, dfs3(vertex,adj_scc,prof));
	}
	cout << maxi;
}
