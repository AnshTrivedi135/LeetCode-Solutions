class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                // Pop the right operand first
                int num2 = st.top(); st.pop();
                // Pop the left operand second
                int num1 = st.top(); st.pop();
                
                // Perform the respective operation
                if (token == "+") st.push(num1 + num2);
                else if (token == "-") st.push(num1 - num2);
                else if (token == "*") st.push(num1 * num2);
                else if (token == "/") st.push(num1 / num2);
            } else {
                // Convert string to integer and push to stack
                st.push(stoi(token));
            }
        }
        
        return st.top();
    }
};
