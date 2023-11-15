class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    int last = n - 1;
    while (last > - 1&& nums[last] <= 0)last--;
    for (int i = 0; i <= last; i++) {
        if (nums[i] <= 0) {
            swap(nums[i], nums[last]);
            last--;
            while (last > -1 && nums[last] <= 0)last--;
        }
    }

    int k = last+1;
    
    for (int i = 0; i < k; i++) {
        if (nums[i] <= 0)return i + 1;
        while (nums[i] <= k && nums[nums[i]-1] != nums[i]) {
            swap(nums[nums[i]-1], nums[i]);
        }
    }
    for (int i = 0; i < k; i++) {
        if (nums[i] != i + 1)return i+1;
    }
    return k + 1;
}
};
