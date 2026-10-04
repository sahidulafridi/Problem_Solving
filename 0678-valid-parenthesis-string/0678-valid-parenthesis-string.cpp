//Leetcode POTD solution for 04 oct

#include <string>
#include <algorithm>
class Solution {
public:
bool checkValidString(std::string s) {
int minOpen = 0;
int maxOpen = 0;
for (char c : s) {
if (c == '(') {
minOpen++;
maxOpen++;
} else if (c == ')') {
minOpen--;
maxOpen--;
} else if (c == '*') {
minOpen--;
maxOpen++;
}
if (maxOpen < 0) {
return false;
}
minOpen = std::max(minOpen, 0);
}
return minOpen == 0;
}
};
