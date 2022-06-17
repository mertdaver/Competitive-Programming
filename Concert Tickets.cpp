#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    multiset<int> s;
    for (int i = 0; i < n; i++) {
        int h; cin >> h; s.insert(-h);
    }
    for (int i = 0; i < m; i++) {
        int x; cin >> x;
        auto it = s.lower_bound(-x);
        if (it == s.end())cout << -1 << '\n';
        else{
            cout << -1 * (*it) << '\n';
            s.erase(it);
        }
    }
}
