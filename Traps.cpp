#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <stack>
#include <set>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
int N,K;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define loop(x, n) for(int x = 0; x < n; ++ x)

void solve() {
    cin >> N >> K;
    vector<int> traps(N); vector<pair<int,int>> v(N);
    for (int i = 0; i < N; i++) {
        cin >> traps[i];
        v[i] = { traps[i] - (N - 1 - i),i };
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    vector<int> comp;
    for (int i = 0; i < K; i++) {
        comp.push_back(v[i].second);
    }
    sort(comp.begin(), comp.end());
    int l = 0;
    int add = 0;
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (l < comp.size() && i == comp[l]) {
            l++;
            add++;
        }
        else {
            ans += traps[i] + add;
        }
    }
    cout << ans << '\n';
}

int main()
{
    fast;
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
