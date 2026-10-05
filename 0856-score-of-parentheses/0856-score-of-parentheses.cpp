//Leetcode POTD solution for 05 oct


class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0); // Root level accumulator

        for (char c : s) {
            if (c == '(') {
                st.push(0);
            } else {
                int v = st.top();
                st.pop();
                
                // If v == 0, it was "()", score is 1.
                // Otherwise, it was "(A)", score is 2 * A.
                int score = max(2 * v, 1);
                
                // Add to the score of the outer parent group
                st.top() += score;
            }
        }

        return st.top();
    }
};

//for Daily POTD(Unstop/leetcode/GFG) follow @POTDunstop
