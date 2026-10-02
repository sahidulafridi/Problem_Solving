//Leetcode POTD solution for 2 oct
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void backtrack(int n, int open_count, int close_count, string current, vector<string>& result) {
        // Base case: string has reached max length 2 * n
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Option 1: Add an open parenthesis if we haven't reached n open parentheses
        if (open_count < n) {
            backtrack(n, open_count + 1, close_count, current + '(', result);
        }

        // Option 2: Add a close parenthesis if it won't exceed the number of open parentheses
        if (close_count < open_count) {
            backtrack(n, open_count, close_count + 1, current + ')', result);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n, 0, 0, "", result);
        return result;
    }
};
