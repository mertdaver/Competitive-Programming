#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, x; cin >> n >> x;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first; v[i].second = i;
    }
    sort(v.begin(), v.end());
    int l, r; l = 0; r = n - 1;
    int i1, i2; i1 = 0; i2 = 0;
    while (l < r) {
        if (v[l].first + v[r].first == x) { i1 = v[l].second; i2 = v[r].second; break; }
        if (v[l].first + v[r].first > x) { r--; }
        else if (v[l].first + v[r].first < x) { l++; }
    }
    if (i1 == 0 && i2 == 0)cout << "IMPOSSIBLE" << endl;
    else cout << i1 + 1 << " " << i2 + 1 << endl;
}
