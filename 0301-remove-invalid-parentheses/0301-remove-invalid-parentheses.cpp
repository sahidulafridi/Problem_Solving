//Leetcode POTD solution for 07 oct

class Solution {
public:
    // Helper function to check if a string has valid parentheses
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') {
                count++;
            } else if (c == ')') {
                count--;
                if (count < 0) return false;
            }
        }
        return count == 0;
    }

    vector<string> removeInvalidParentheses(string s) {
        vector<string> result;
        unordered_set<string> visited;
        queue<string> q;

        q.push(s);
        visited.insert(s);
        bool found = false;

        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            // If a valid string is found at the current level
            if (isValid(curr)) {
                result.push_back(curr);
                found = true;
            }

            // Once we find a valid string, stop generating longer removals (next level)
            if (found) continue;

            // Generate all possible states by removing one parenthesis at a time
            for (int i = 0; i < curr.length(); i++) {
                if (curr[i] != '(' && curr[i] != ')') continue;

                string next_str = curr.substr(0, i) + curr.substr(i + 1);

                if (visited.find(next_str) == visited.end()) {
                    visited.insert(next_str);
                    q.push(next_str);
                }
            }
        }

        return result;
    }
};

