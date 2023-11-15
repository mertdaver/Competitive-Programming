#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

vector<set<int>> enter;
vector<pair<int,int>> leave;
vector<bool> good;
vector<vector<int>> cycles;
vector<int> ord;

void dfs(int v) {
	ord.push_back(v);
	good[v] = 0;
	int u = leave[v].first;
	if (good[u])dfs(u);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	long long result = 0;
	enter.resize(n + 1, set<int>());
	leave.resize(n + 1, { 0, 0 });
	good.resize(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		leave[i] = { a,b };
		enter[a].insert(i);
	}
	set<pair<int, int>> inDegree;
	for (int i = 1; i <= n; i++) {
		inDegree.insert({ enter[i].size(),i });
	}
	while (!inDegree.empty() && inDegree.begin()->first == 0) {
		auto pi = *inDegree.begin(); inDegree.erase(inDegree.begin());
		good[pi.second] = 0;
		result += leave[pi.second].second; //adding the edge weight to the result;
		inDegree.erase({enter[leave[pi.second].first].size(),leave[pi.second].first});
		enter[leave[pi.second].first].erase(pi.second);
		inDegree.insert({ enter[leave[pi.second].first].size(),leave[pi.second].first });
	}

	for (int i = 1; i <= n; i++) {
		if (!good[i])continue;
		dfs(i);
		cycles.push_back(ord);
		ord.clear();
	}

	for (auto arr : cycles) {
		long long sum = 0;
		int exiled = 1e9;
		for (int i = 0; i < arr.size(); i++) {
			sum += leave[arr[i]].second;
			exiled = min(leave[arr[i]].second, exiled);
		}
		sum -= exiled;
		result += sum;
	}

	cout << result << '\n';
}
