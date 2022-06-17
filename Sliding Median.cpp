#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n, k; cin >> n >> k;
    multiset<int> s;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int l = 0; int r = 0;
    while (r < k) {
        s.insert(v[r]);
        r++;
    }
    auto it = s.begin();
    advance(it, k / 2);
    ll med = *it;
    while (r < n) {
        cout << med << " ";
        s.erase(s.find(v[l]));
        s.insert(v[r]);
        if (v[l] >= med && v[r] <= med) {
            it--;
        }
        if (v[l] <= med && v[r] >= med) {
            it++;
        }
        med = *it;
        l++;r++;
    }
    cout << med;
}