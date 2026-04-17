class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int n = static_cast<int>(s.size()), l = 0, ans = (n ? 1 : 0);
        mp[s[0]]++;

        for (int r = 1; r < n; ++r) {
            while (l < r && mp.count(s[r])) {
                mp[s[l]]--;

                if (!mp[s[l]]) {
                    mp.erase(s[l]);
                }

                l++;
            }

            mp[s[r]]++;
            ans = max(ans, r - l + 1);
        }

        return ans;
    }
};
