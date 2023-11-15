#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
const int MOD = 1e9 + 9;
#define PI pair<int,int>
ll dp[1005][1005][11];
int N, M, K;

int main()
{
    freopen("team.in", "r", stdin);
    freopen("team.out", "w", stdout);
    cin >> N >> M >> K;
    vector<ll> john(N+1);
    vector<ll> paul(M+1);

    for (int i = 1; i <= N; i++) {
        cin >> john[i];
    }
    for (int i = 1; i <= M; i++) {
        cin >> paul[i];
    }

    sort(paul.begin(), paul.end());
    sort(john.begin(), john.end());

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j][0] = 1;
        }
    }

    for (int k = 1; k <= K; k++) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                if(k>0)dp[i][j][k] = 0;
                if (i) {
                    dp[i][j][k] += dp[i - 1][j][k];
                }
                if (j) {
                    dp[i][j][k] += dp[i][j - 1][k];
                }
                if (i&&j) {
                    dp[i][j][k] -= dp[i - 1][j - 1][k];
                }
                if ((i&&j) && john[i] > paul[j]) {
                    dp[i][j][k] += dp[i - 1][j - 1][k - 1];
                }
                dp[i][j][k] %= MOD;
                dp[i][j][k] += MOD;
                dp[i][j][k] %= MOD;
            }
        }
    }

    cout << dp[N][M][K] % MOD;
}
