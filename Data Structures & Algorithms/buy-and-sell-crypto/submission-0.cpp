class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = static_cast<int>(prices.size()), ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, prices[j] - prices[i]);
            }
        }

        return ans;
    }
};
