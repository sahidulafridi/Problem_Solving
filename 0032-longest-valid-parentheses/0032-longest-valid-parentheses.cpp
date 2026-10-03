//Leetcode POTD solution for 03 oct

#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
int longestValidParentheses(std::string s) {
std::stack<int> st;
// Initialize the stack with -1 to serve as a base for length calculation
st.push(-1);
int max_len = 0;

for (int i = 0; i < s.length(); ++i) {
if (s[i] == '(') {
// Store the index of the opening parenthesis
st.push(i);
} else {
// Pop the top element when we encounter a closing parenthesis
st.pop();

if (st.empty()) {
// If the stack is empty, it means the current closing parenthesis
// is unmatched and acts as a new boundary base index.
st.push(i);
} else {
// Calculate the current valid length by subtracting the current index
// from the index of the last unmatched element at the top of the stack.
max_len = std::max(max_len, i - st.top());
}
}
}

return max_len;
}
};
