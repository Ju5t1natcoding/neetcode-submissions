class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = static_cast<int>(nums.size()) - 1, ans = nums[0];

        while (l <= r) {
            int mij = l + ((r - l) >> 1);

            if (nums[mij] <= nums.back()) {
                ans = nums[mij];
                r = mij - 1;
            } else {
                l = mij + 1;
            }
        }

        return ans;
    }
};
