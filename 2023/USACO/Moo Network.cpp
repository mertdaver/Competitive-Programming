#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <queue>
#include <map>
#include <queue>

using namespace std;
typedef long long ll;
#define PI pair<ll,ll>
int N;
vector<vector<ll>> adj;
vector<PI> dots;
map<PI, ll> indexes;

ll MST() {
	priority_queue<PI, vector<PI>, greater<PI>> pq;
	ll result = 0;
	pq.push({ 0,0 });
	vector<bool> visited(N, 0);
	while (!pq.empty()) {
		ll vertex = pq.top().second;
		ll price = pq.top().first;
		pq.pop();
		if (visited[vertex]) continue;
		visited[vertex] = 1;
		auto p1 = dots[vertex];
		result += price;
		for (int u : adj[vertex]) {
			if (visited[u]) continue;
			auto p2 = dots[u];
			ll dist = pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2);
			pq.push({ dist,u });
		}
	}
	return result;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	adj.resize(N + 1,vector<ll>());
	dots.resize(N);
	vector<vector<ll>> Y(11);
	for (int i = 0; i < N; i++) {
		cin >> dots[i].first >> dots[i].second;
		indexes[dots[i]] = i;
		Y[dots[i].second].push_back(dots[i].first);
 	}

	for (int h = 0; h <= 10; h++) {
		sort(Y[h].begin(), Y[h].end());
	}

	for (int level = 0; level <= 10; level++) {
		for (int vertex : Y[level]) {
			ll idx = indexes[{vertex, level}];
			for (int curr = level; curr <= 10; curr++) {
				auto it = lower_bound(Y[curr].begin(), Y[curr].end(), vertex);
				if (it!=Y[curr].end()&&curr == level) {
					it++;
				}
				if (it != Y[curr].end()) {
					ll temp = indexes[{*it, curr}];
					adj[idx].push_back(temp);
					if(curr!=level)adj[temp].push_back(idx);
				}
				it = lower_bound(Y[curr].begin(), Y[curr].end(), vertex);
				if (it != Y[curr].begin()) {
					it--;
					ll temp = indexes[{*it, curr}];
					adj[idx].push_back(temp);
					if(curr!=level)adj[temp].push_back(idx);
				}
			}
		}
	}

	ll result = MST();
	cout << result << '\n';
}
