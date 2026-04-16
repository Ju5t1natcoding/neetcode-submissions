class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> fr;
        int n = static_cast<int>(nums.size());

        for (int i = 0; i < n; ++i) {
            fr[nums[i]] = i;
        }

        for (int i = 0; i < n; ++i) {
            if (fr.count(target - nums[i]) && fr[target - nums[i]] != i) {
                return {i, fr[target - nums[i]]};
            }
        }

        return {}; ///nu cred ca ar ajunge aici dar na pt safety
    }
};
