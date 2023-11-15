#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
ll INF = 1e18;
ll d[505][505];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int N, M, Q; cin >> N >> M >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            d[i][j] = INF;
        }
        d[i][i] = 0;
    }
    for (int i = 0; i < M; i++) {
        ll a, b, c; cin >> a >> b >> c;
        d[a][b] = min(c,d[a][b]);
        d[b][a] = min(c, d[b][a]);
    }
    for (int k = 1; k <= N; k++) {
        for (int j = 1; j <= N; j++) {
            for (int i = 1; i <= N; i++) {
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
            }
        }
    }
    while (Q--) {
        int a, b; cin >> a >> b;
        if(d[a][b]>=INF)d[a][b]=-1;
        cout << d[a][b] << '\n';
    }
}
