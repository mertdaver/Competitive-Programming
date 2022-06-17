#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    ll l, r, last;
    l = 0; r = 0; last = 0;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    set<int> s; map<int, int> m;
    ll ans = 0;
    while (r < n) {
        if (s.size() >= k + 1) {
            r--;
            ll l1 = r - l; 
            ll l2 = last - l;
            ans += (l1 - l2) * (l1 + l2 + 1) / 2;
            last = r; //- 1;
            while (s.size() && s.size() > k) {
                if (m[v[l]] == 1) {
                    s.erase(v[l]);
                    m.erase(v[l]);
                }
                else {
                    m[v[l]]--;
                }
                l++;
            }
            r++;
        }
        else {
            s.insert(v[r]);
            m[v[r]]++;
            r++;
        }
    }
    if (s.size() >= k + 1) {
        r--;
        ll l1 = r - l;
        ll l2 = last - l; 
        ans += (l1 - l2) * (l1 + l2 + 1) / 2;
        last = r; //- 1;
        while (s.size() && s.size() > k) {
            if (m[v[l]] == 1) {
                s.erase(v[l]);
                m.erase(v[l]);
            }
            else {
                m[v[l]]--;
            }
            l++;
        }
        r++;
    }
    ll l1 = r - l;
    ll l2 = last - l;
    ans += (l1 - l2) * (l1 + l2 + 1) / 2;
    cout << ans;
}