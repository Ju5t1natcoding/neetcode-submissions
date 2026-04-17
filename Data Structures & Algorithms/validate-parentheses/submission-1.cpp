class Solution {
    inline int idx(char c) {
        return (c == '(' || c == ')') ? 0 : ((c == '[' || c == ']') ? 1 : 2);
    }

public:
    bool isValid(string s) {
        int n = static_cast<int>(s.size());
        stack<int> st;

        for (int i = 0; i < n; ++i) {
            bool popper = (s[i] == ')' || s[i] == ']' || s[i] == '}');
            int k = idx(s[i]);

            if ((st.empty() || (!st.empty() && st.top() != k)) && popper) {
                return false;
            }

            if (popper) {
                st.pop();
            } else {
                st.push(k);
            }
        }

        return st.empty();
    }
};
