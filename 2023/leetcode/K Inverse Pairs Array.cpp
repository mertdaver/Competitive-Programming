class Solution {
public:
    const int MOD = 1e9 + 7;
    int kInversePairs(int n, int k) {
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1));
        vector<vector<long long>> prefDP(n + 1, vector<long long>(k+1,0));

        for (int i = 0; i <= n; i++)dp[i][0] = 1;
        for (int i = 0; i <= n; i++)prefDP[i][0] += dp[i][0];
        for (int i = 1; i <= k; i++)prefDP[0][i] = prefDP[0][i - 1];

        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {
                prefDP[i][j] = prefDP[i][j - 1];
                if (i < 7) {
                    int temp = 1;
                    for (int c = 1; c <= i; c++)temp *= c;
                    if (temp < j)continue;
                }
                dp[i][j] = prefDP[i-1][j];
                if (j >= i)dp[i][j] -= prefDP[i - 1][j - i];
                prefDP[i][j] += dp[i][j]; prefDP[i][j] %= MOD;
            }
        }
        while (dp[n][k] < 0)dp[n][k] += MOD;
        return dp[n][k] % MOD;
    }
};


//dp[i][j] = dp[i-1][j] + dp[i-1][j-1] + dp[i-1][j-2] + ... + d[i][j-(i-1)]
//dp[i][j] = prefDP[i-1]
