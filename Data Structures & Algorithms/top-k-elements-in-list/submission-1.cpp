class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int, int>> v;
        int n = static_cast<int>(nums.size());

        for (int i = 0; i < n; ++i) {
            bool ok = false;
            for (auto& [x, f] : v) {
                if (nums[i] == x) {
                    f++;
                    ok = true;
                    break;
                }
            }

            if (!ok) {
                v.push_back({nums[i], 1});
            }
        }

        sort(begin(v), end(v), [](pair<int, int> x, pair<int, int> y) {
            if (x.second != y.second) {
                return x.second > y.second;
            }

            return x.first < y.first;
        });

        vector<int> ans;
        for (auto [x, _] : v) {
            ans.push_back(x);

            if (static_cast<int>(ans.size()) == k) {
                return ans;
            }
        }

        return ans;
    }
};
