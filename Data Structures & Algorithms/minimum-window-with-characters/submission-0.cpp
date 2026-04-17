class Solution {
public:
    string minWindow(string s, string t) {
        int n = static_cast<int>(s.size()), m = static_cast<int>(t.size());

        if (n < m) {
            return "";
        }

        unordered_map<char, int> mp, fr;
        int l = 0, dim = 50000;
        string ans = "";

        for (int i = 0; i < m; ++i) {
            mp[t[i]]++;
        }

        function<bool()> valid = [&]() {
            for (auto p : mp) {
                auto it = fr.find(p.first);

                if (it == end(fr) || p.second > it->second) {
                    return false;
                }
            }

            return true;
        };

        for (int r = 0; r < n; ++r) {
            fr[s[r]]++;

            while (valid()) {
                if (dim > r - l + 1) {
                    dim = r - l + 1;
                    ans = s.substr(l, dim);
                }

                fr[s[l]]--;
                l++;
            }
        }

        return ans;
    }
};
