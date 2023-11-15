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
int dp[105][100005];

int main()
{
    fast;
    cin >> N;
    vector<int> coins(N+1);
    int sum = 1;
    for (int i = 1; i <= N; i++) {
        cin >> coins[i]; sum += coins[i];
    }
    loop(i, N+1) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w < sum; w++) {
            dp[i][w] = dp[i - 1][w];
            if (w - coins[i] < 0)continue;
            dp[i][w] = max(dp[i-1][w - coins[i]], dp[i][w]);
        }
    }
    vector<int> ans;
    for (int w = 1; w < sum; w++) {
        loop(i, N+1) {
            if (dp[i][w]) {
                ans.push_back(w);
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << " ";
    }
    cout << ans[ans.size() - 1];
}
