#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;
typedef long long ll;
const ll INF = 1e18;
int N, M, K;
vector<vector<pair<int, int>>> adj;

void Dijkstra(vector<ll>& d) {
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	vector<int> done(N + 1,0);
	pq.push({ 0,1 });
	int check = K;
	while (K) {
		ll v = pq.top().second, price = pq.top().first; pq.pop();
		if (done[v] > check)continue;
		done[v]++; 
		if (v == N) {
			--K;
			d.push_back(price);
			if (!K)break;
		}
		for (pair<int, int> pii : adj[v]) {
			ll u = pii.second, w = pii.first;
			pq.push({ w + price,u });
		}
	}
}

int main()
{
	cin >> N >> M >> K;
	adj.resize(N + 1, vector<pair<int, int>>());
	for (int i = 0; i < M; i++) {
		int a, b, c; cin >> a >> b >> c;
		adj[a].push_back({ c,b });
	}
	vector<ll> d;
	Dijkstra(d);
	for (ll price : d) {
		cout << price << " ";
	}
}
