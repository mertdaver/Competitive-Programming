#include <iostream>
#include <string>
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
    string S, T; cin >> S >> T;
    N = S.size()+1, M = T.size()+1;
    vector<vector<int>> dp(N, vector<int>(M));
    loop(i, N) {
        dp[i][0] = i;
    }
    loop(j, M) {
        dp[0][j] = j;
    }
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {
            dp[i][j] = min(dp[i - 1][j] + 1, dp[i - 1][j - 1] + (S[i-1] != T[j-1]));
            dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1);
        }
    }
    cout << dp[S.size()][T.size()];
}