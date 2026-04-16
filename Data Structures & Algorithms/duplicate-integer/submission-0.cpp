#include <unordered_map>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> fr;
        bool ok = false;

        for (int x : nums) {
            if (fr.count(x)) {
                ok = true;
                break;
            }

            fr[x] = true;
        }

        return ok;
    }
};