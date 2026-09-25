#include <string>
#include <vector>
#include <set>

class Solution {
public:
    std::vector<std::string> braceExpansionII(std::string expression) {
        return dfs(expression, 0, expression.length() - 1);
    }

private:
    std::vector<std::string> dfs(const std::string& expr, int start, int end) {
        std::set<std::string> unique_words;
        // groups maintains the concatenation groups separated by commas
        std::vector<std::vector<std::string>> groups{{}}; 
        int layer = 0;
        int left = 0;

        for (int i = start; i <= end; ++i) {
            if (expr[i] == '{') {
                if (++layer == 1) {
                    left = i + 1; // Mark start of the inner expression
                }
            } else if (expr[i] == '}') {
                if (--layer == 0) {
                    // We found a matching closing brace, process its expanded sub-problem
                    merge(groups, dfs(expr, left, i - 1));
                }
            } else if (expr[i] == ',' && layer == 0) {
                // A comma at the top layer means we start a new union group
                groups.push_back({});
            } else if (layer == 0) {
                // A regular character at the top layer
                merge(groups, {std::string(1, expr[i])});
            }
        }

        // Combine all groups (union operation) into a single set to deduplicate and sort
        for (const auto& group : groups) {
            for (const std::string& word : group) {
                unique_words.insert(word);
            }
        }

        return std::vector<std::string>(unique_words.begin(), unique_words.end());
    }

    // Performs Cartesian product concatenation between the last group and the new sub-group
    void merge(std::vector<std::vector<std::string>>& groups, const std::vector<std::string>& new_group) {
        if (groups.back().empty()) {
            groups.back() = new_group;
            return;
        }
        std::vector<std::string> merged;
        for (const std::string& word1 : groups.back()) {
            for (const std::string& word2 : new_group) {
                merged.push_back(word1 + word2);
            }
        }
        groups.back() = merged;
    }
};