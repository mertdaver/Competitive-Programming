#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    ll l, r; l = 0; r = pow(10, 18);
    while (l < r) {
        ll mid = (l + r) / 2;
        ll free = k;
        ll sum = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            if (free == 0 || v[i] > mid) {
                flag = false;
                break;
            }
            if (sum + v[i] > mid) {
                free--;
                sum = v[i];
            }
            else {
                sum += v[i];
            }
        }
        if (!flag || !free) {
            l = mid + 1;
        }
        else {
            r = mid;
        }
    }
    cout << l;
}
