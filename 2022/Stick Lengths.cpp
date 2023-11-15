#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    long long ans = 1e18;
    long long cur = 0;
    for (int i = 0; i < n; i++) {
        cur += abs(v[n / 2] - v[i]);
    }
    ans = min(cur, ans);
    for (int i = 0; i < n; i++) {
        cur += abs(v[n / 2 + 1] - v[i]);
    }
    ans = min(cur, ans);
    cout << ans << endl;
}
