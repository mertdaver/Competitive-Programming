#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <tuple>

using namespace std;
typedef long long ll;
const int INF = 1e9 + 1;
const ll MOD = 1e9 + 7;
int N, Q;
//unsigned int plane[100000000];

#define fast ios::sync_with_stdio(0);cin.tie(0);

int main()
{
    fast;
    cin >> N >> Q;
    vector<int> v(N);
    int maxi = 0;
    for (int i = 0; i < N; i++) {
        cin >> v[i]; maxi = max(maxi, v[i] + 1);
    }
    int M = maxi;
    int root = sqrt(M);
    vector<vector<int>> blocks(M / root + 1,vector<int>());
    vector<int> roots(M / root + 1);
    for (int i = 0; i < N; i++) {
        roots[v[i] / root]++;
        blocks[v[i] / root].push_back(v[i]);
    }
    while (Q--) {
        char ch; cin >> ch;
        if (ch == '?') {
            int a, b; cin >> a >> b;
            ll ans = 0;
            int i = 0;
            for (;i <= b - root && i <= N; i += root) {
                ans += roots[i / root];
            }
            for (int sal : blocks[i / root]) {
                ans += sal <= b;
            }
            i = 0;
            for (;i <= a - root && i<=N; i += root)
                ans -= roots[i / root];
            for (int sal : blocks[i / root]) {
                ans -= sal < a;
            }
            cout << ans << '\n';
        }
        else {
            int k, x; cin >> k >> x; k--;
            roots[v[k] / root]--;
            for (int i = blocks[v[k] / root].size()-1; i >= 0; i--) {
                if (blocks[v[k] / root][i] == v[k]) {
                    blocks[v[k] / root][i] = INF;
                    break;
                }
            }
            v[k] = x;
            roots[v[k] / root]++;
            blocks[v[k] / root].push_back(v[k]);
        }
    }
}
