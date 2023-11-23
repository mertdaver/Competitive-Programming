#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
const int arrSZ = 1e5 + 3;
const int MOD = 1e9 + 7;
ll dp[arrSZ][3];
//bool visited[arrSZ];
vector<vector<int>> adj;

ll N, K;

inline void modnum(ll& num) {
	num %= MOD;
	num += MOD;
	num %= MOD;
}

void init() {
	freopen("barnpainting.in", "r", stdin);
	freopen("barnpainting.out", "w", stdout);
	cin >> N >> K;
	for (int i = 0; i < arrSZ; i++) {
		for (int j = 0; j < 3; j++) dp[i][j] = 1;
	}
	adj.resize(N, vector<int>());
	for (int i = 0; i < N - 1; i++) {
		int x, y; cin >> x >> y; --x; --y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}

	for (int i = 0; i < K; i++) {
		int b, c; cin >> b >> c; --c; --b;
		for (int j = 0; j < 3; j++) {
			if (j == c)continue;
			dp[b][j] = 0;
		}
	}
}

void dfs(int v, int par) {
	for (int u : adj[v]) {
		if (u == par)continue;
		dfs(u, v);
	}

	for (int c = 0; c < 3; c++) {
		for (int u : adj[v]) {
			if (u == par)continue;

			ll currSum = 0;
			for (int cc = 0; cc < 3; cc++) {
				if (cc == c)continue;
				currSum += dp[u][cc];
				modnum(currSum);
			}
			dp[v][c] *= currSum;
			modnum(dp[v][c]);
		}
	}
}

int main(){
	init();
	dfs(0, 0);
	ll result = 0;
	for (int c = 0; c < 3; c++) {
		if (dp[0][c] != -1)result += dp[0][c];
	}
	modnum(result);
	cout << result;
}
