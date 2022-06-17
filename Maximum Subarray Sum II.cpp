#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    ll n, a, b, ans = -2e18; cin >> n >> a >> b;
    vector<ll> reisha(n + 1);
    reisha[0] = 0;
    for (int i = 1; i <= n;i++) {
        cin >> reisha[i];
        reisha[i] += reisha[i - 1];
    }
    multiset<ll> ms;
    for (int i = a;i <= n;i++) {
        ms.insert(reisha[i - a]);
        ans = max(ans, reisha[i] - *ms.begin());
        if (i >= b) {
            ms.erase(ms.find(reisha[i - b]));
        }
    }
    cout << ans;
}





















/*ios::sync_with_stdio(0); cin.tie(0);
ll n, a, b; cin >> n >> a >> b;
vector<ll> v(n);
vector<ll> reisha(n);
cin >> v[0];
reisha[0] = v[0];
for (int i = 1; i < n; i++) {
    cin >> v[i];
    reisha[i] = reisha[i - 1] + v[i];
}
ll l, r, len, k; l = 0; r = 0; len = a; k = l;
ll sum = 0;
ll ans = 0;
ll sub = 0;
set<pair<ll, ll>> s;
while (r < a) {
    sum += v[r++];
}
ans = sum;
while (r < n) {
    if (len > a) {
        s.insert({ reisha[k],k++ });
    }
    while (s.size() && s.begin()->first - reisha[l] < 0) {
        if (s.begin()->second > l && s.begin()->second < k) {
            sub += s.begin()->first - (reisha[l] - v[l]);
            sum -= s.begin()->first - (reisha[l] - v[l]);
            l = s.begin()->second + 1;
            len = r - l;
            ans = max(ans, sum);
            s.erase(s.begin());
            break;
        }
        s.erase(s.begin());
    }
    if (len == b) {
        sub += v[l];
        sum -= v[l];
        len--;
        s.erase({reisha[l],l++ });
        if (len >= a) {
            ans = max(ans, sum);
        }
    }
    sum += v[r];
    len++;
    s.insert({ reisha[r],r });
    if (len >= a) {
        ans = max(ans, sum);
    }
    r++;
}
if (len > a) {
    s.insert({ reisha[k],k++ });
}
while (s.size() && s.begin()->first - reisha[l] <= 0) {
    if (s.begin()->second >= l && s.begin()->second < k) {
        sub += s.begin()->first - (reisha[l] - v[l]);
        sum -= s.begin()->first - (reisha[l] - v[l]);
        l = s.begin()->second + 1;
        len = r - l;
        ans = max(ans, sum);
    }
    s.erase(s.begin());
}
std::cout << ans;*/