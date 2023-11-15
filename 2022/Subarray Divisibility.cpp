#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    vector<pair<ll, ll>> r(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i]; v[i] %= n; v[i] += n; v[i] %= n;
    }
    r[0].first = 0; r[0].second = -2147483648;
    for (int i = 1; i <= n; i++) {
        r[i].first = r[i - 1].first + v[i - 1]; r[i].first %= n; r[i].first += n; r[i].first %= n;
        r[i].second = i - 1;
    }
    ll ans = 0;
    sort(r.begin(), r.end());
    for (int i = 0; i < n; i++) {
        auto it = r.begin(); advance(it, i);
        pair<ll, ll> p = { r[i].first + 1, -2147483648 };
        auto tmp = lower_bound(r.begin(), r.end(), p); tmp--;
        ans += tmp - it;
    }
    cout << ans;
}
