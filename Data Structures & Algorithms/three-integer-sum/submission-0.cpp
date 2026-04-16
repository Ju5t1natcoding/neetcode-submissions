class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, set<int>> mp;
        vector<vector<int>> ans;
        set<vector<int>> s;
        int n = static_cast<int>(nums.size());
        sort(begin(nums), end(nums));

        for (int i = 0; i < n; ++i) {
            mp[nums[i]].insert(i);
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (!mp.count(-nums[i]-nums[j])) {
                    continue;
                }

                auto& v = mp[-nums[i]-nums[j]];
                for (int k : v) {
                    if (i == k || j == k) {
                        continue;
                    }

                    if (s.count({min({i, j, k}), i + j + k - min({i, j, k}) - max({i, j, k}), max({i, j, k})})) {
                        continue;
                    }

                    ans.push_back({min({nums[i], nums[j], nums[k]}), nums[i] + nums[j] + nums[k] - min({nums[i], nums[j], nums[k]}) - max({nums[i], nums[j], nums[k]}), max({nums[i], nums[j], nums[k]})});
                    s.insert({min({i, j, k}), i + j + k - min({i, j, k}) - max({i, j, k}), max({i, j, k})});
                }
            }
        }

        s.clear();
        s = set<vector<int>>(begin(ans), end(ans));
        ans.clear();

        for (auto it : s) {
            ans.push_back(it);
        }

        return ans;
    }
};
