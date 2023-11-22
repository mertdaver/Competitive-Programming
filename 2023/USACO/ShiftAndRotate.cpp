#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;
typedef long long ll;
#define PI pair<ll,ll>
#define PII pair<ll,PI>
ll N, K, T;


inline void MOD(ll& num) {
	num %= N;
	num += N;
	num %= N;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K >> T;
	vector<ll> nxtPos(N);
	vector<ll> A(K);
	vector<PI> dist(N); //dist from pusher
	for (int i = 0; i < K; i++) {
		cin >> A[i];
	}

	int pnt = 0;
	int lastIdx = K - 1;
	int d = N - A[K - 1];
	for (int i = 0; i < N; i++) {
		nxtPos[i] = i;
		if (pnt < K && i == A[pnt]) {
			pnt++;
			d = 0;

			lastIdx++;
			if (lastIdx == K)lastIdx = 0;
		}
		else {
			d++;
		}
		dist[i] = { d,lastIdx };
	}

	for (int i = 0; i < N; i++) {
		ll dj = abs((A[(dist[i].second + 1) % K] - A[dist[i].second]));
		if (dist[i].second == K - 1) {
			dj = N - dj;
		}

		MOD(dj);

		if (T <= dist[i].first) continue;
		ll times = (T-dist[i].first+(dj-1))/dj;
		nxtPos[i] += times * dj;
		MOD(nxtPos[i]);
	}

	vector<int> answer(N);
	for (int i = 0; i < N; i++) {
		answer[nxtPos[i]] = i;
	}
	for (int i = 0; i < N-1; i++) {
		cout << answer[i] << " ";
	}
	cout << answer[N - 1] << '\n';
}
