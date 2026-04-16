class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        sort(begin(nums), end(nums));
        vector<vector<int>> ans;

        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                break;
            }

            if (i && nums[i] == nums[i - 1]) {
                continue;
            }

            int l = i + 1, r = n - 1;

            while (l < r) {
                int val = nums[i] + nums[l] + nums[r];

                if (val > 0) {
                    r--;
                } else if (val < 0) {
                    l++;
                } else {
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;

                    while (l < r && nums[l] == nums[l - 1]) {
                        l++;
                    }
                }
            }
        }

        return ans;
    }
};
