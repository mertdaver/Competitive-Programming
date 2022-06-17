#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        v.push_back(x);
    }
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        auto it = ms.upper_bound(v[i]);
        if (it == ms.end()) { ms.insert(v[i]); }
        else {
            ms.erase(it);
            ms.insert(v[i]);
        }
    }
    cout << ms.size() << endl;
}
