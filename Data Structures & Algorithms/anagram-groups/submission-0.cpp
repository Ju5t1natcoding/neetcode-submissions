class Solution {
    inline bool isAnagram(const string& s, const string& t) {
        vector<int> fr(26, 0);
        for (char c : s) {
            fr[c - 'a']++;
        }

        for (char c : t) {
            fr[c - 'a']--;
        }

        for (int i = 0; i < 26; ++i) {
            if (fr[i]) {
                return false;
            }
        }

        return true;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = static_cast<int>(strs.size()), dim = 0;

        for (int i = 0; i < n; ++i) {
            bool ok = false;
            for (int j = 0; j < dim; ++j) {
                if (isAnagram(strs[i], ans[j][0])) {
                    ans[j].push_back(strs[i]);
                    ok = true;
                    break;
                }
            }

            if (!ok) {
                dim++;
                ans.emplace_back();
                ans.back().push_back(strs[i]);
            }
        }

        return ans;
    }
};
