class Solution {
public:
    bool isValid(string s) {
        string st = ""; 
        
        for (char c : s) {
            if (c == 'c') {
                int n = st.length();
                
                if (n >= 2 && st[n - 1] == 'b' && st[n - 2] == 'a') {
                    st.pop_back(); 
                    st.pop_back(); 
                } else {
                    return false;
                }
            } else {
                st.push_back(c); 
            }
        }
        
        return st.empty();
    }
};
