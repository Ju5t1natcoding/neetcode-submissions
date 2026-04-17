class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = static_cast<int>(heights.size()), ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans = max(ans, min(heights[i], heights[j]) * (j - i));
            }
        }

        return ans;
    }
};
