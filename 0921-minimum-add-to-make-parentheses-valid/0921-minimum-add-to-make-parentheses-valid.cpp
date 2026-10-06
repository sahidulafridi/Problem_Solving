//LeetCode POTD solution for 06 oct

#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minAddToMakeValid(string s) {
        int openCount = 0;
        int additionsNeeded = 0;

        for (char c : s) {
            if (c == '(') {
                openCount++;
            } else {
                if (openCount > 0) {
                    openCount--; // Matched with an existing '('
                } else {
                    additionsNeeded++; // Unmatched ')', needs a '(' before it
                }
            }
        }

        // Total moves = unmatched ')' + unmatched '('
        return additionsNeeded + openCount;
    }
};
//for Daily POTD(Unstop/leetcode/GFG) follow @POTDunstop
