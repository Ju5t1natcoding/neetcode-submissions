class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = static_cast<int>(nums.size()), ans = 0;
        sort(begin(nums), end(nums));

        for (int i = n - 1; i >= 0; --i) {
            mp[nums[i]] = mp[nums[i] + 1] + 1;
            ans = max(ans, mp[nums[i]]);
        }

        return ans;
    }
};
