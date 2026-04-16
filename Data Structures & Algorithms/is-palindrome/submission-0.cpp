class Solution {
    inline bool verifyable(char c) {
        return ('0' <= c && c <= '9') || ('a' <= c && c <= 'z');
    }

public:
    bool isPalindrome(string s) {
        for (char& c : s) {
            if ('A' <= c && c <= 'Z') {
                c += 32;
            }
        }

        int l = 0, r = static_cast<int>(s.size()) - 1;

        while (l < r) {
            while (!verifyable(s[l])) {
                l++;
            }

            while (!verifyable(s[r])) {
                r--;
            }

            if (l >= r) {
                break;
            }

            if (s[l] != s[r]) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }
};
