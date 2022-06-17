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
int N, M;
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define loop(x, n) for(int x = 0; x < n; ++ x)

int main()
{
    fast;
    cin >> N >> M;
    vector<vector<int>> dp(N + 1, vector<int>(M + 1));
    int first; cin >> first;
    for (int i = 1; i <= M; i++) {
        dp[0][i] = first == 0 || first == i;
    }
    for (int i = 1; i < N; i++) {
        int x; cin >> x;
        if (x == 0) {
            for (int j = 1; j <= M; j++) {
                if (j < M) {
                    dp[i][j] += dp[i - 1][j + 1];
                    dp[i][j] %= MOD;
                }
                if (j > 1) {
                    dp[i][j] += dp[i - 1][j - 1];
                    dp[i][j] %= MOD;
                }
                dp[i][j] += dp[i - 1][j];
                dp[i][j] %= MOD;
            }
        }
        else {
            if (x < M) {
                dp[i][x] += dp[i - 1][x + 1];
                dp[i][x] %= MOD;
            }
            if (x > 1) {
                dp[i][x] += dp[i - 1][x - 1];
                dp[i][x] %= MOD;
            }
            dp[i][x] += dp[i - 1][x];
            dp[i][x] %= MOD;
        }
    }
    ll sum = 0;
    for (int i = 1; i <= M;i++) {
        sum += dp[N - 1][i]; sum %= MOD;
    }
    cout << sum;
}
