class Solution {
public:

    //let's say we've calculated the pref array. 
    //when we are at index I, we want to find the nearest to the left
    //index j, whose pref value is smaller than pref[i]-k (instead of pref[i], which)
    //we know how to solve
    //pref[i]-(pref[i]-k)
    #define PI pair<ll,ll>
    typedef long long ll;
    int shortestSubarray(vector<int>& nums, int k) {
    int n = nums.size();
    vector<ll> pref(n, 0);
    pref[0] = nums[0];
    for (int i = 1; i < n; i++)pref[i] = pref[i - 1] + nums[i];
    deque<PI> mono;// mono.push_back({ 0,n });
    ll result = 1e9;

    for (int i = 0; i < n; i++) {
        if (pref[i] >= k) { result = i + 1; break; }
    }

    for (int i = 0; i < n; i++) {
        while (!mono.empty() && mono.back().first > pref[i]) {
            mono.pop_back();
        }
        mono.push_back({ pref[i],i });
        while (mono.size() > 1 && pref[i] - mono.front().first >= k) {
            result = min(result, i - mono.front().second);
            mono.pop_front();
        }
    }
    if (result == 1e9)return -1;
    return result;
    }
};
