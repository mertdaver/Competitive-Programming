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
ll dp[(ll)1e5+5][21][4];
int N, K;

int match(int a, int b) {
    if (a == 1 && b == 3) return 1;
    if (a == 2 && b == 1) return 1;
    if (a == 3 && b == 2) return 1;
    return 0;
}

int main()
{
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    cin >> N >> K;
    vector<char> FJ(N+1);

    //H = 1, P = 2, S = 3
    for (int i = 0; i < N; i++) {
        char ch; cin >> ch;
        int res = 0;
        if (ch == 'H') res = 1;
        if (ch == 'P') res = 2;
        if (ch == 'S') res = 3;
        FJ[i] = res;
    }
    for (int ges = 1; ges <= 3; ges++) {
        for(int k = 0; k <= K; k++)
            dp[N][k][ges] = 0;
    }
    for (int k = 0; k <= K; k++) {
        if (k == 1) {
            int asda = 0;
        }
        for (int i = N-1; i >= 0; i--) {
            for (int ges = 1; ges <= 3; ges++) {
                dp[i][k][ges] = dp[i + 1][k][ges] + match(ges, FJ[i]);
                if (k > 0) {
                    ll maxi = 0;
                    for (int g = 1; g <= 3; g++)maxi = max(maxi, dp[i][k - 1][g]);
                    dp[i][k][ges] = max(dp[i][k][ges], maxi);
                }
            }
        }
    }
    ll maxi = 0;
    for (int g = 1; g <= 3; g++)maxi = max(maxi, dp[0][K][g]);
    cout << maxi;
}
