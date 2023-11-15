class Solution {
public:
int longestValidParentheses(string s) {
    int n = s.length();

    vector<int> nums(n, 0);
    vector<int> pref(n, 0);
    vector<vector<int>> val(2 * n + 1, vector<int>());

    if (n == 0)return 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') { nums[i] = 1; }
        else { nums[i] = -1; }
    }

    pref[0] = nums[0];
    for (int i = 1; i < n; i++) {
        pref[i] = pref[i - 1] + nums[i];
    }

    int result = 0;
    val[pref[0] + n].push_back(0);
    for (int i = 1; i < n; i++) {
        if (pref[i] - 1 + n < 0 || pref[i] - 1 + n >= 2*n)continue;
        int temp = val[pref[i] - 1 + n].size();
        if (temp) {
            result = max(result, i - (val[pref[i] - 1 + n][temp - 1] + 1));
        }
        else {
            if (val[pref[i] + n].size()) {
                result = max(result, i - val[pref[i] + n][0]);
            }
            if (pref[i] == 0) {
                result = max(result, i + 1);
            }
        }
        val[pref[i] + n].push_back(i);
    }

    return result;
}
};
