class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> fr;
        for (char c : s) {
            fr[c]++;
        }

        for (char c : t) {
            fr[c]--;
        }

        unordered_map<char, int>::iterator it;
        for (it = begin(fr); it != end(fr); ++it) {
            if (it->second) {
                return false;
            }
        }

        return true;
    }
};
