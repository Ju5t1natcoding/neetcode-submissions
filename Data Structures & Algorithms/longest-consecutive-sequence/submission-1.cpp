class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums));
        int ans = 0;

        for (int x : nums) {
            if (!s.count(x - 1)) {
                int lg = 1;

                while (s.count(x + lg)) {
                    lg++;
                }

                ans = max(ans, lg);
            }
        }

        return ans;
    }
};
