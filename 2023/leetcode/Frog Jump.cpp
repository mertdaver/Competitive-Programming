class Solution {
public:
    int binarySearch(vector<int>& stones, int target) {
    int n = stones.size();
    int l = 0; int r = n - 1;
    int mid = (l + r) / 2;
    while (l < r) {
        if (stones[mid] == target) {
            break;
        }
        if (stones[mid] > target) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
        mid = (l + r) / 2;
    }
    if (stones[mid] != target) {
        return -1;
    }
    return mid;
}

bool canCross(vector<int>& stones) {
    if(stones[1]!=1)return 0;
    int n = stones.size();
    vector<vector<bool>> dp(n, vector<bool>(n+5));

    for (int k = 1; k <= n + 3; k++)dp[n - 1][k] = 1;

    for (int i = n - 2; i>0; i--) {
        for (int k = 1; k <= n + 1; k++) {
            int nxt = binarySearch(stones, stones[i] + k);
            if (nxt == -1)continue;
            dp[i][k] = max(max(dp[nxt][k - 1], dp[nxt][k]), dp[nxt][k + 1]);
        }
    }

    return max(dp[1][1], dp[1][2]);
}
};
