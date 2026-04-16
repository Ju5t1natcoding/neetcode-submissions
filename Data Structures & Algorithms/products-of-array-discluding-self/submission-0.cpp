class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        vector<int> pref(n, 1), suf(n, 1);

        pref[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pref[i] = pref[i - 1] * nums[i];
        }

        suf[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            suf[i] = suf[i + 1] * nums[i];
        }

        vector<int> ans(n);
        ans[0] = suf[1];
        ans[n - 1] = pref[n - 2];

        for (int i = 1; i < n - 1; ++i) {
            ans[i] = pref[i - 1] * suf[i + 1];
        }

        return ans;
    }
};
