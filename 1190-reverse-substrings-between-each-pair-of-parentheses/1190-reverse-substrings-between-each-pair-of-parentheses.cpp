#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string reverseParentheses(std::string s) {
        std::stack<int> openBrackets;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                // Store the index of the open parenthesis
                openBrackets.push(i);
            } 
            else if (s[i] == ')') {
                // Get the matching open parenthesis index
                int start = openBrackets.top();
                openBrackets.pop();
                
                // Reverse the substring inside the matching pair
                std::reverse(s.begin() + start + 1, s.begin() + i);
            }
        }
        
        // Construct the final answer omitting parentheses
        std::string result = "";
        for (char c : s) {
            if (c != '(' && c != ')') {
                result += c;
            }
        }
        
        return result;
    }
};