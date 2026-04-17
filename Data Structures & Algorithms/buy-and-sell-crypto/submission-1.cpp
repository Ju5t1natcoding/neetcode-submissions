class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = static_cast<int>(prices.size()), l = 0, ans = 0;
        for (int r = 1; r < n; ++r) {
            if (prices[r] > prices[l]) {
                ans = max(ans, prices[r] - prices[l]);
            } else {
                l = r;
            }
        }

        return ans;
    }
};
