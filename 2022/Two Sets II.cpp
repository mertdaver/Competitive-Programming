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
int N;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define loop(x, n) for(int x = 0; x < n; ++ x)
ll dp[505][63378];

int main()
{
    fast;
    cin >> N;
    dp[1][1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int k = 1; k <= i * (i + 1) / 2; k++) {
            dp[i][k] += dp[i - 1][k];
            if (dp[i][k] >= MOD)dp[i][k] %= MOD;
            if (k >= i) { dp[i][k] += dp[i - 1][k-i]; }
            if (dp[i][k] >= MOD)dp[i][k] %= MOD;
        }
    }
    ll val = N * (N + 1) / 2;
    if (val % 2 == 0) {
        val /= 2;
        cout << dp[N][val];
    }
    else {
        cout << 0;
    }
}
