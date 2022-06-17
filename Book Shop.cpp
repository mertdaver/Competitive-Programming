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
#define fast ios::sync_with_stdio(0);cin.tie(0);
#define loop(x, n) for(int x = 0; x < n; ++ x)

int main()
{
    fast;
    cin >> N >> X;
    vector<int> W(N); vector<int> P(N);
    loop(i, N) {
        cin >> W[i];
    }
    loop(i, N) {
        cin >> P[i];
    }
    vector<vector<int>> dp(N, vector<int>(X + 1));
    dp[0][W[0]] = P[0];
    for (int i = W[0]+1; i <= X; i++) {
        dp[0][i] = dp[0][i - 1];
    }
    for (int i = 1; i < N; i++) {
        for (int w = 1; w <= X; w++) {
            dp[i][w] = dp[i - 1][w];
            if (W[i] > w)continue;
            dp[i][w] = max(dp[i][w], dp[i - 1][w - W[i]] + P[i]);
        }
    }
    cout << dp[N - 1][X];
}
