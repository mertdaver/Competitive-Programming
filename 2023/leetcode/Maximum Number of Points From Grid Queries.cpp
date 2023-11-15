class Solution {
public:
    typedef long long ll;
    #define PI pair<ll,ll>
    #define PII pair<ll,pair<ll,ll>>
    int lowerb(vector<PI>& v, int target) {
    int l = 0;
    int r = v.size() - 1;
    int mid = (l + r) / 2;
    int sol = 0;
    while (l <= r) {
        if (target < v[mid].first) {
            r = mid - 1;
        }
        else {
            sol = mid;
            l = mid + 1;
        }
        mid = (l + r) / 2;
    }
    return v[sol].second;
}

vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m));
    vector<PI> values;
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    ll maxi = 0;
    ll result = 0;
    pq.push({ grid[0][0],{0,0} });
    visited[0][0] = true;
    while (!pq.empty()) {
        int i = pq.top().second.first;
        int j = pq.top().second.second;
        int price = pq.top().first;
        pq.pop();
        if (price > maxi) {
            values.push_back({ maxi,result });
            maxi = price;
        }
        result++;
        if (i > 0 && !visited[i - 1][j]) {
            pq.push({ grid[i - 1][j],{i - 1,j} });
            visited[i - 1][j] = true;
        }
        if (j > 0 && !visited[i][j - 1]) {
            pq.push({ grid[i][j - 1],{i,j - 1} });
            visited[i][j - 1] = true;
        }
        if (i < n - 1 && !visited[i + 1][j]) {
            pq.push({ grid[i + 1][j],{i + 1,j} });
            visited[i + 1][j] = true;
        }
        if (j < m - 1 && !visited[i][j + 1]) {
            pq.push({ grid[i][j + 1],{i,j + 1} });
            visited[i][j + 1] = true;
        }
    }
    values.push_back({ maxi,result });
    vector<int> answer;
    for (int i = 0; i < queries.size(); i++) {
        answer.push_back(lowerb(values, queries[i]-1));
    }
    return answer;
    }
};
