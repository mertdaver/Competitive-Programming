#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

typedef long long ll;
int N, M, C;
int TSIZE = 1000;
vector<int> adj[1005];
ll mooney[1005];
ll dp[1005][1005]; //dp[N][T]
const ll INF = 1e9;

void solve() {
	dp[0][0] = 0;
	for (int T = 0; T < TSIZE; T++) {
		for (int i = 0; i < N; i++) {
			for (int u : adj[i]) {
				dp[i][T + 1] = max(dp[i][T + 1], dp[u][T] + mooney[i] - C*(2*T+1));
			}
		}
	}
}

int main()
{
	ifstream fin("time.in");
	ofstream fout("time.out");

	fin >> N >> M >> C;
	for (int i = 0; i < N; i++) {
		fin >> mooney[i];
	}
	for (int i = 0; i < M; i++) {
		int u, v; fin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
	}
	for (int i = 0; i < 1000; i++) {
		for (int T = 0; T < TSIZE; T++) {
			dp[i][T] = -INF;
		}
	}
	solve();
	ll result = 0;
	for (int T = 0; T < TSIZE; T++) {
		result = max(result, dp[0][T]);
	}

	fout << result << '\n';

	fin.close();
	fout.close();
}
