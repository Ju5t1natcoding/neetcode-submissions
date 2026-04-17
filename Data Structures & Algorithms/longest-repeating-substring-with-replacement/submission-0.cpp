class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = static_cast<int>(s.size()), l, ans = 0, curr; ///curr = current number of replacements
        
        for (int i = 0; i < 26; ++i) {
            char c = static_cast<char>(i + 'A');
            l = 0;
            curr = 0;

            for (int r = 0; r < n; ++r) {
                curr += (s[r] != c);
                
                while (curr > k) {
                    curr -= (s[l] != c);
                    l++;
                }

                ans = max(ans, r - l + 1);
            }
        }

        return ans;
    }
};