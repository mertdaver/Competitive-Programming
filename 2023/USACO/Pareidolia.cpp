#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

#define PIP pair<int,pair<int,int>>
#define PI pair<int,int>

class Compare {
public:
    bool operator()(PI below, PI above)
    {
        if (below.first < above.first) {
            return true;
        }
        else if (below.first == above.first
            && below.second > above.second) {
            return true;
        }

        return false;
    }
};


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    int n = s.size();
    vector<int> price(n, 0);
    vector<int> suffix(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) { cin >> price[i]; sum += price[i]; }
    suffix[n-1] = price[n-1];
    for (int i = n-2; i >= 0; i--)suffix[i] = suffix[i + 1] + price[i];
    
    vector<vector<PI>> dp(n, vector<PI>(2, {0,0})); //dp[i] = {length,actualSum}
    //sum := sum of invalid ones, will be the final answer. 

    vector<priority_queue<PI,vector<PI>,Compare>> heaps(6, priority_queue<PI, vector<PI>, Compare>());
    // = {len,{FactoredSum,RealSum}}
    //In the case of the char e, factoredSum == ActualSum

    heaps[5].push({0,0});
    
    for (int i = 0; i < n; i++) {

        char ch = s[i];
        if (ch == 'b') {
            
            dp[i][0] = { heaps[5].top().first + 1, heaps[5].top().second};
            heaps[0].push({ dp[i][0].first,dp[i][0].second + suffix[i] - price[i] });

            //dp[i][0] = {heaps[5].top().first + 1,heaps[5].top().second + price[i]};
            //heaps[0].push(dp[i][0]);
        }
        if (ch == 'e') {

            if (!heaps[0].empty()) {
                dp[i][0] = {
                    heaps[0].top().first,
                    heaps[0].top().second - suffix[i]
                };
            }

            if (!heaps[4].empty()) {
                dp[i][1] = {
                    heaps[4].top().first,
                    heaps[4].top().second - suffix[i]
                };
            }
            heaps[1].push({ 
                dp[i][0].first,
                dp[i][0].second + suffix[i] - price[i] 
            });

            heaps[5].push({ 
                dp[i][1].first,
                dp[i][1].second 
            }); // + suffix[i] - price[i] });

        }
        if (ch == 's') {

            if (heaps[1].size())dp[i][0] = { heaps[1].top().first,heaps[1].top().second - suffix[i] };
            if (heaps[2].size())dp[i][1] = { heaps[2].top().first,heaps[2].top().second - suffix[i] };
            heaps[2].push({ dp[i][0].first,dp[i][0].second + suffix[i] - price[i] });
            heaps[3].push({ dp[i][1].first,dp[i][1].second + suffix[i] - price[i] });

        }
        if (ch == 'i'){
            if (heaps[3].size())dp[i][0] = { heaps[3].top().first,heaps[3].top().second - suffix[i] };
            heaps[4].push({ dp[i][0].first,dp[i][0].second + suffix[i] - price[i] });

            //if(heaps[3].size())dp[i][0] = { heaps[3].top().first,heaps[3].top().second + price[i] };
            //heaps[4].push(dp[i][0]);
        }
    }

    int len = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'e') {
            len = max(len, dp[i][1].first);
        }
    }
    int result = 1e9;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'e' && dp[i][1].first == len) {
            result = min(result, dp[i][1].second);
        }
    }

    cout << len << '\n';
    cout << result << '\n';
}
