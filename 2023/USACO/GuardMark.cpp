#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
typedef long long ll;
#define PI pair<ll,ll>

int main()
{
    freopen("guard.in", "r", stdin);
    freopen("guard.out", "w", stdout);

    ll N, H; cin >> N >> H;
    vector<ll> height(N);
    vector<ll> weight(N);
    vector<ll> strength(N);
    vector<PI> dp(1 << N,{-1,0});

    for (int i = 0; i < N; i++) {
        cin >> height[i] >> weight[i] >> strength[i];
    }

    for (int j = 0; j < N; j++) {
        dp[1 << j] = { height[j],strength[j] };
    }

    for (int s = 1; s < (1 << N); s++) {
        for (int p = 0; p < N; p++) {
            if (s & (1 << p)) {
                auto option = dp[s ^ (1 << p)];
                if (option.first == -1)continue;
                if (option.second - weight[p] < 0)continue;
                option.first += height[p];
                option.second = min(option.second - weight[p], strength[p]);
                dp[s] = max(dp[s], option);
            }
        }
    }

    ll result = -1;
    for (int s = 1; s < (1 << N); s++) {
        if (dp[s].first >= H) {
            result = max(result, dp[s].second);
        }
    }

    if (result == -1) {
        cout << "Mark is too tall";
    }
    else {
        cout << result;
    }
}
