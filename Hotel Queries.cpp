#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
int N, Q;

#define fast ios::sync_with_stdio(0);cin.tie(0);

int main()
{
    fast;
    cin >> N >> Q;
    int root = sqrt(N);
    vector<int> v(N);
    vector<int> blocks(N);
    vector<int> roots(N / root + 1);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        blocks[i] = i / root;
        roots[blocks[i]] = max(roots[blocks[i]], v[i]);
    }
    while (Q--) {
        int r; cin >> r;
        int pos = 0;
        for (int i = 0; i < roots.size(); i++) {
            if (roots[i] >= r) {
                int l = root * i;
                while (v[l] < r) { ++l; }
                v[l] -= r;
                pos = l+1;
                roots[i] = 0;
                for (int j = root * i; j < root * (i + 1); j++) {
                    roots[i] = max(roots[i], v[j]);
                }
                break;
            }
        }
        cout << pos << " ";
    }
}
