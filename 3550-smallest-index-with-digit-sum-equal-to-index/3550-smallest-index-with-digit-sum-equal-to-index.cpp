#include <vector>

class Solution {
public:
    int smallestIndex(std::vector<int>& nums) {
        // Lambda function to calculate the sum of digits of a number
        auto digitSum = [](int n) {
            if (n == 0) return 0;
            int s = 0;
            while (n > 0) {
                s += n % 10;
                n /= 10;
            }
            return s;
        };
        
        for (int i = 0; i < nums.size(); ++i) {
            if (digitSum(nums[i]) == i) {
                return i;
            }
        }
        
        return -1;
    }
};