#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
 
using namespace std;
typedef long long ll;
 
const int MOD = 1e9 + 7;
 
int lowerb(vector<int>& v, int target) { //return the largest number who is smaller than target.
    int l = 0;
    int r = v.size() - 1;
    int mid = (l + r) / 2;
    int sol = 0;
    
    while (l <= r) {
        if (target >= v[mid]) {
            sol = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
        mid = (l + r) / 2;
    }
    //if (v[r] <= target) sol = r;
 
    return v[sol];
}
 
void solve() {
    int n, k; cin >> n >> k;
    vector<vector<vector<ll>>> dp(n + 1, vector<vector<ll>>(k + 1, vector<ll>(n + 1,0))); //dp[i-index][j-location is sequence][m-block number]
    vector<int> C(n,0);
    
    for (int i = 0; i < n; i++) 
        cin >> C[i];
 
    vector<vector<int>> hist(n+1,vector<int>(1,0));
 
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j][0] = 1;
        }
    }
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int lastCi = lowerb(hist[C[i - 1]], i);
            for (int m = 1; m <= n / k; m++) {
                if (j == k) {
                    dp[i][j][m] = (dp[i - 1][j][m] + dp[lastCi][k - 1][m]) % MOD;
                }
                else{ // 1 <= j <= k-1
                    if (j > 1)
                        dp[i][j][m] = (dp[lastCi][j - 1][m] + dp[lastCi][j][m])%MOD;
 
                    else
                        dp[i][j][m] = (dp[i - 1][k][m - 1] + dp[lastCi][j][m])%MOD;
 
                }
                dp[i][j][m] %= MOD;
            }
        }
        hist[C[i - 1]].push_back(i);
    }
    
    int result = 1;
    for (int m = n/k; m >= 0; m--) {
        if (dp[n][k][m] > 0) {
            result = dp[n][k][m];
            break;
        }
    }
 
    cout << result % MOD << '\n';
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        solve();
    }
}
