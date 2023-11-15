#include <iostream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int main()
{
    int n,x; cin >> n >> x;
    vector<int> v(n);
    vector<pair<ll,ll>> r(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    r[0].first = 0; r[0].second = -1;
    for (int i = 1; i <= n; i++) {
        r[i].first = r[i - 1].first + v[i-1];
        r[i].second = i-1;
    }
    ll ans = 0;
    sort(r.begin(), r.end());
    for (int i = 0; i <= n; i++) {
        pair<ll, ll> p = { x + r[i].first ,r[i].second + 1};
        auto it = lower_bound(r.begin(), r.end(), p);
        p = { x + r[i].first + 1, -2147483648};
        auto tmp = lower_bound(r.begin(), r.end(), p);
        ans += tmp - it;
        if (it == r.end()) { it = r.begin(); }
    }
    cout << ans;
}
