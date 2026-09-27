class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for (char ch : s) {

            // Opening bracket
            if (ch == '(') {
                st.push(ch);
            }

            // Closing bracket
            else if (ch == ')') {

                string temp;

                // '(' tak characters nikaalo
                while (!st.empty() && st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }

                // '(' remove karo
                st.pop();

                // Reversed string wapas stack me daalo
                for (char c : temp) {
                    st.push(c);
                }
            }

            // Normal character
            else {
                st.push(ch);
            }
        }

        // Stack se answer banao
        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};