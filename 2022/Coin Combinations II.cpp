#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <tuple>
#include <stack>

using namespace std;
typedef long long ll;
const int INF = 1e9;
const ll MOD = 1e9 + 7;
int N, X;
vector<int> C;
#define fast ios::sync_with_stdio(0);cin.tie(0);

int dp[1000005];

int main()
{
    fast;
    cin >> N >> X;
    C.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }
    dp[0] = 1;
    sort(C.begin(), C.end());
    for (int w = 0; w < N; w++) {
        for (int i = 1; i <= X; i++) {
            if (i - C[w] < 0)continue;
            dp[i] += dp[i - C[w]]; dp[i] %= MOD;
        }
    }
    cout << dp[X];
}
