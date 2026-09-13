#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1, ones2;

        // Collect coordinates of all 1s
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) ones1.emplace_back(r, c);
                if (img2[r][c] == 1) ones2.emplace_back(r, c);
            }
        }

        // Count occurrences of each shift vector (dr, dc)
        // Encode (dr, dc) into a single integer or use an array/map
        // Since -n < dr, dc < n, offset by n to make indices non-negative: [0, 2*n]
        vector<vector<int>> shift_counts(2 * n + 1, vector<int>(2 * n + 1, 0));
        int max_overlap = 0;

        for (const auto& [r1, c1] : ones1) {
            for (const auto& [r2, c2] : ones2) {
                int dr = r2 - r1 + n;
                int dc = c2 - c1 + n;
                shift_counts[dr][dc]++;
                max_overlap = max(max_overlap, shift_counts[dr][dc]);
            }
        }

        return max_overlap;
    }
};