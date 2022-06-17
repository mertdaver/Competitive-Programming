#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;
typedef long long ll;
const ll INF = 1e18;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int N, M; cin >> N >> M;
    vector<ll> d(N + 1, 0);
    vector<int> p(N + 1, -1);
    vector<tuple<int, int, int>> edges(M);
    int x;
    for (int i = 0; i < M; i++) {
        int a, b, c; cin >> a >> b >> c;
        edges[i] = { a,b,c };
    }
    for (int i = 0; i < N; i++) {
        x = -1;
        for (tuple<int,int,int> tii : edges) {
            int a, b, c; tie(a, b, c) = tii;
            if (d[a] + c < d[b]) {
                d[b] = d[a] + c;
                p[b] = a;
                x = b;
            }
        }
    }
    if (x == -1) {
        cout << "NO";
    }
    else {
        for (int i = 0; i < N; i++)
            x = p[x];

        vector<int> cycle;
        for (int v = x;; v = p[v]) {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());
        cout << "YES" << '\n';
        for (int v : cycle)
            cout << v << " ";
    }
}
