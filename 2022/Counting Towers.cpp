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
int T,N;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define loop(x, n) for(int x = 0; x < n; ++ x)

ll dp[1000005][2];

int main()
{
    fast;
    dp[1][0] = dp[1][1] = 1;
    for(int i = 2; i <= 1000000; i++){
        dp[i][0] = 2 * dp[i - 1][0] + dp[i - 1][1]; dp[i][0] %= MOD;
        dp[i][1] = 4 * dp[i - 1][1] + dp[i - 1][0]; dp[i][1] %= MOD;
    }
    cin >> T;
    while (T--) {
        cin >> N;
        ll ans = (dp[N][0] + dp[N][1]) % MOD;
        cout << ans << '\n';
    }
}
