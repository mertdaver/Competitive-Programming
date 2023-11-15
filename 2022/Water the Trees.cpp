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
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
int N,maxi;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define loop(x, n) for(int x = 0; x < n; ++ x)

bool func(ll A, ll B, vector<int> h) {
    int idx = 0;
    while (A) {
        if (idx == N)break;
        if (A >= (maxi-h[idx]) / 2) {
            A -= (maxi - h[idx]) / 2;
            h[idx] += 2 * ((maxi - h[idx]) / 2);
        }
        else {
            h[idx] += 2 * A;
            A = 0;
        }
        idx++;
    }
    idx = 0;
    while (B) {
        if (idx == N)break;
        if (B >= maxi - h[idx]) {
            B -= maxi - h[idx];
            h[idx] += maxi - h[idx];
        }
        else {
            h[idx] += B;
            B = 0;
        }
        idx++;
    }
    bool flag = 1;
    for (int i = 0; i < N; i++) {
        if (h[i] < maxi) {
            flag = 0; break;
        }
    }
    return flag;
}

int main()
{
    fast;
    int t; cin >> t;
    while (t--) {
        cin >> N;
        vector<int> h(N);
        maxi = 0;
        ll ans = INF;
        for (int i = 0; i < N; i++) { cin >> h[i]; maxi = max(h[i], maxi); }
        ll tmp = maxi;
        for (;maxi <= tmp+1; maxi++) {
            ll l = 0, r = pow(2,62);
            while (l < r) {
                ll mid = (l + r) / 2;
                ll a = mid / 2, b = (mid+1) / 2;
                if (func(a, b, h)) {
                    r = mid;
                }
                else {
                    l = mid + 1;
                }
            }
            ans = min(ans, l);
        }
        cout << ans << '\n';
    }
}
