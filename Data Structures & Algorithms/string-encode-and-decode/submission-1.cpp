class Solution {
public:

    string encode(vector<string>& strs) {
        string ans = "";
        for (auto& s : strs) {
            if (s == "") {
                ans += '|';
                continue;
            }

            for (char c : s) {
                int x = c;
                ans += to_string(x);
                ans += ',';
            }
            
            ans.pop_back();
            ans += '|';
        }

        return ans;
    }

    vector<string> decode(string s) {
        int n = static_cast<int>(s.size());
        vector<string> ans;
        string curr = "";

        for (int i = 0; i < n; ++i) {
            if ('0' <= s[i] && s[i] <= '9') {
                int j = i;
                string nr;

                while (j < n && '0' <= s[j] && s[j] <= '9') {
                    nr += s[j];
                    j++;
                }

                int x = stoi(nr);
                curr += static_cast<char>(x);
                i = j - 1;
            } else if (s[i] == '|') {
                ans.push_back(curr);
                curr = "";
            }
        }

        ///ans.push_back(curr);
        return ans;
    }
};
