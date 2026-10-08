//Leetcode POTD solution for 08 oct

#include <string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int depth = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (depth > 0) {
                    result += c;
                }
                depth++;
            } else {
                depth--;
                if (depth > 0) {
                    result += c;
                }
            }
        }
        
        return result;
    }
};
//for Daily POTD(Unstop/leetcode/GFG) follow @POTDunstop
