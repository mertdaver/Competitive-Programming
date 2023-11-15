#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define PI pair<int,int>
int dp[605][605];
int W,H,N;

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> W >> H >> N;

    for (int i = 1; i < 605; i++) {
        for (int j = 1; j < 605; j++) {
            dp[i][j] = i * j;
        }
    }
    for (int i = 0; i < N; i++) {
        int wi, hi; cin >> wi >> hi;
        dp[wi][hi] = 0;
    }

    for (int x = 1; x <= W; x++) {
        for (int y = 1; y <= H; y++) {
            for (int c = 1; c < x; c++) {
                dp[x][y] = min(dp[x][y], dp[c][y] + dp[x - c][y]);
            }
            for (int c = 1; c < y; c++) {
                dp[x][y] = min(dp[x][y], dp[x][c] + dp[x][y - c]);
            }
        }
    }

    cout << dp[W][H] << '\n';
}
