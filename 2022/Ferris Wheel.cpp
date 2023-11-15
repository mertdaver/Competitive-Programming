#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    //vector<int> v(n);
    multiset<int,greater<int>> s;
    for (int i = 0; i < n; i++) {
        int p; cin >> p;
        s.insert(p);
    }
    int cnt = 0;
    while (s.size()) {
        cnt++;
        int p = *s.begin();
        s.erase(s.begin());
        auto it = s.lower_bound(x - p);
        if (it == s.end())continue;
        s.erase(it);
    }
    cout << cnt << '\n';
}
