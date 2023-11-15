class Solution {
public:
    int candy(vector<int>& ratings) {
    int n = ratings.size();
    if (n == 1)return 1;
    vector<pair<int, int>> B(n);
    vector<pair<int, int>> A;
    for (int i = 0; i < n; i++) {
        B[i] = { ratings[i],i };
    }
    //sort(A.begin(), A.end());
    vector<queue<pair<int, int>>> hist(2 * 1e4 + 5,queue<pair<int,int>>());
    for (int i = 0; i < n; i++) {
        hist[B[i].first].push(B[i]);
    }
    for (int i = 0; i < hist.size(); i++) {
        while (!hist[i].empty()) {
            A.push_back(hist[i].front());
            hist[i].pop();
        }
    }

    vector<int> ans(n);

    int result = 0;

    for (int j = 0; j < n; j++) {
        int idx = A[j].second;
        ans[idx] = 1;
        
        if (idx > 0) {
            if(ratings[idx] > ratings[idx-1])ans[idx] = max(ans[idx], ans[idx - 1] + 1);
        }
        if (idx < n - 1) {
            if (ratings[idx] > ratings[idx + 1])ans[idx] = max(ans[idx], ans[idx + 1] + 1);
        }
        result += ans[idx];
    }
    //for (int i = 0; i < n; i++)result += ans[i];

    return result;
}
};
