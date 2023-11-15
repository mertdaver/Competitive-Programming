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
vector<vector<int>> adj;
vector<int> par,sz;
int N, M;

int find_set(int a) {
	if (a == par[a])
		return a;
	return par[a] = find_set(par[a]);
}

bool unite(int a,int b) {
	int pa = find_set(a), pb = find_set(b);
	if (pa == pb)
		return false;
	if (sz[pa] > sz[pb])
		swap(pa, pb);
	par[pa] = pb;
	sz[pb] += sz[pa];
	return true;
}
void connected(int v,vector<bool>& done) {
	for (int u : adj[v]) {
		if (done[u])continue;
		done[u] = 1;
		connected(u, done);
	}
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> N >> M;
	int comps = N; int maxi = 1;
	par.resize(N + 1); sz.resize(N + 1, 1); adj.resize(N + 1, vector<int>());
	vector<tuple<int, int, int>> edges(M);
	for (int i = 1; i <= N; i++) {
		par[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		edges[i] = { c,a,b };
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	ll ans = 0;
	vector<bool> done(N + 1, 0);
	done[1] = 1;
	connected(1, done);
	bool flag = false;
	for (int i = 1; i <= N;i++) {
		if (!done[i]) { flag = true;break; }
	}
	if (flag)cout << "IMPOSSIBLE";
	else {
		sort(edges.begin(), edges.end());
		for (int i = 0; i < M; i++) {
			int a, b, c; tie(c, a, b) = edges[i];
			if (unite(a, b))
				ans += c;
		}
		cout << ans;
	}
}
