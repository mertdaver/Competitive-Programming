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
    cin >> N;
    int root = sqrt(N);
    vector<int> blocks(N);
    vector<int> roots(N / root + 1);
    vector<int> v(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];
        blocks[i] = i / root;
        roots[blocks[i]]++;
    }
    while (N--) {
        if (N == 4) {
            int asdas = 0;
        }
        int p; cin >> p;
        int idx = 0;//, i = 0;
        while (p > roots[idx]) {
            p -= roots[idx];
            //i += root;
            idx++;
        }
        int i = idx * root;
        while (v[i] == -1)++i;
        while (p > 1) {
            if (v[i] != -1) { --p; }
            i++;
        }
        while (v[i] == -1)++i;
        cout << v[i] << " ";
        v[i] = -1;
        roots[idx]--;
    }
}
