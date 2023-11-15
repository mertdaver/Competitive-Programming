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
int N;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define loop(x, n) for(int x = 0; x < n; ++ x)
vector<int> a, b;

void solve() {
    cin >> N;
    a.resize(N);
    b.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> b[i];
    }
    int i = N - 1, j = N - 1;
    multiset<int> s;
    while (i&&j) {
        while (j > 0 && b[j] == b[j - 1]) {
            s.insert(b[j]);
            j--;
        }
        if (b[j] == a[i]) {
            --j;--i;
        }
        else {
            if (s.count(a[i])) {
                s.erase(s.find(a[i]));
                i--;
            }
            else {
                cout << "NO" << '\n';
                return;
            }
        }
    }
    cout << "YES" << '\n';
    a.clear();
    b.clear();
}

int main()
{
    fast;
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
