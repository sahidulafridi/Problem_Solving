#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::string evaluate(std::string s, std::vector<std::vector<std::string>>& knowledge) {
        // Step 1: Convert knowledge into a hash map for efficient O(1) lookups
        std::unordered_map<std::string, std::string> lookup;
        for (const auto& pair : knowledge) {
            lookup[pair[0]] = pair[1];
        }

        std::string result = "";
        std::string current_key = "";
        bool is_key = false;

        // Step 2: Iterate through the string in a single pass
        for (char c : s) {
            if (c == '(') {
                is_key = true;
            } else if (c == ')') {
                is_key = false;
                // Look up the extracted key in our map
                if (lookup.count(current_key)) {
                    result += lookup[current_key];
                } else {
                    result += "?";
                }
                current_key.clear(); // Clear the temp key for the next pair
            } else if (is_key) {
                current_key += c; // Build the key string
            } else {
                result += c; // Regular text outside of brackets
            }
        }

        return result;
    }
};