class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = static_cast<int>(nums.size()) - 1;

        while (l <= r) {
            int mij = l + ((r - l) >> 1);

            if (nums[mij] == target) {
                return mij;
            }

            if (target <= nums.back()) {
                if (nums[mij] > nums.back() || nums[mij] < target) {
                    l = mij + 1;
                } else {
                    r = mij - 1;
                }
            } else {
                if (nums[mij] <= nums.back() || nums[mij] > target) {
                    r = mij - 1;
                } else {
                    l = mij + 1;
                }
            }
        }

        return -1;
    }
};
