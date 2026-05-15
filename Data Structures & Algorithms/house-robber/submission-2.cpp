class Solution {
public:
    int rob(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> dp = nums, mx(n, 0);
        mx[0] = nums[0];
        mx[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; ++i) {
            dp[i] += mx[i - 2];
            mx[i] = max(dp[i], mx[i - 2]);
        }

        return max(mx[n - 2], mx[n - 1]);
    }
};
