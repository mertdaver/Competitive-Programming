#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n, k; cin >> n >> k;
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int, int>>> pq; //which movie's heap
	set<pair<int,int>,greater<pair<int,int>>> free;//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free;
	for (int i = 0; i < n; i++) {
		pair<int, int> p; cin >> p.second >> p.first;
		pq.push(p);
	}
	for (int i = 0; i < k; i++) {
		free.insert({ 0,i });
	}
	ll ans = 0;
	while (pq.size()) {
		pair<int, int> tmp = pq.top();
		auto a = free.end();
		a--;
		while (pq.size() && a->first > pq.top().second) {
			pq.pop();
		}
		if (pq.size()) {
			ans++;
			auto it = free.lower_bound({pq.top().second,2147483648 });
			if (it == free.end()) { it--; }
			free.insert({pq.top().first,it->second });
			free.erase(it);
			pq.pop();
		}
	}
	cout << ans;
}



































/*
#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int n, k; cin >> n >> k;
	vector<pair<int, int>> v(n);
	priority_queue<pair<int, int>,vector<pair<int,int>>,greater<pair<int, int>>> pq; //which movie's heap
	set<pair<int,int>> free;//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> free;
	for (int i = 0; i < n; i++) {
		pair<int, int> p; cin >> p.second >> p.first;
		v[i] = p;
		pq.push(p);
	}
	for (int i = 0; i < k; i++) {
		free.insert({ 0,i });
	}
	ll ans = 0;
	sort(v.begin(), v.end());
	while (pq.size()) {
		pair<int, int> tmp = pq.top();
		auto it = free.begin();
		while (pq.size() && it->first > pq.top().second) {
			pq.pop();
		}
		if (pq.size()) {
			ans++;
			it = free.lower_bound({pq.top().second,-1});
		}
	}
	cout << ans;
}
*/