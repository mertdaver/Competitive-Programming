class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
    int N = nums.size();
    vector<long long> pref(N);
    pref[0] = nums[0];
    for (int i = 1; i < N; i++) {
        pref[i] = pref[i - 1] + nums[i];
    }

    long long ans = 0;

    for (int i = 0; i < N; i++) {

        int l = 0;
        int r = i;
        int mid = (l + r) / 2;
        //int candidate = i;

        if (i == 1) {
            int asldm = 0;
        }

        while (l < r) {
            if ((pref[i] - pref[mid] + nums[mid]) * (i - mid + 1) < k) {
                r = mid-1;
                //candidate = mid;
            }
            else {
                l = mid + 1;
            }
            mid = (l + r) / 2;
        }
        if ((r < 0 || (pref[i] - pref[r] + nums[r]) * (i - r + 1) >= k)) {
            r++;
        };
        ans += i - r + 1;
    }

    return ans;
}
};

//If you look carefully, you might find that there if one looking at all subarrays ending at index i, one can binary search the starting index, which from him towards all subarrays are okay, as if we look : 
//i > i', j -> sum([i',j]) < sum([i,j]) AND len([i',j]) < len([i,j])
//Therfore we'll just binary search the first index,i, from where (pref[j]-pref[i-1])*(j-i+1) <= k (incapable to do so because the sequence is monotonic).
