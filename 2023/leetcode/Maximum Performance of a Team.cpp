
class Solution {
public:
    typedef long long ll;
    const int MOD = 1e9+7;

    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pair<int, int>> workers(n);
    for (int i = 0; i < n; i++) {
        workers[i].first = efficiency[i];
        workers[i].second = speed[i];
    }
    sort(workers.begin(), workers.end(), greater<pair<int, int>>());
    priority_queue<int, vector<int>, greater<int>> pq;

    ll sum = 0; //heap's sum
    ll result = 0;

    for (int i = 0; i < n; i++) {
        pq.push(workers[i].second);

        if (pq.size() <= k) {
            sum += workers[i].second;// sum %= MOD;
            result = max(result, sum * workers[i].first);
            //result %= MOD;
            continue;
        }

        if (pq.top() == workers[i].second) {
            pq.pop();
            result = max(result, (sum - pq.top() + workers[i].second) * workers[i].first);
        }
        else {
            sum -= pq.top();
            pq.pop();
            sum += workers[i].second;
            //sum %= MOD;
            result = max(result, sum * workers[i].first);
        }
        //result %= MOD;
    }

    return result%MOD;
    }
};
