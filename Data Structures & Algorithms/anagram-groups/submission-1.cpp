class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n = static_cast<int>(strs.size());
        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < n; ++i) {
            string tmp = strs[i];
            sort(begin(tmp), end(tmp));
            mp[tmp].push_back(strs[i]);
        }
        
        for (auto it : mp) {
            ans.push_back(it.second);
        }

        return ans;
    }
};
