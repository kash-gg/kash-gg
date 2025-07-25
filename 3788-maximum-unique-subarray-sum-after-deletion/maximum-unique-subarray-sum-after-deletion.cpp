#include <vector>
#include <unordered_set>
#include <algorithm> // Required for std::max_element
#include <numeric>   // Required for std::accumulate

class Solution {
public:
    int maxSum(std::vector<int>& nums) {
        // Create a set of unique numbers from the input vector.
        std::unordered_set<int> unique_nums(nums.begin(), nums.end());
        
        long long positive_sum = 0;
        
        // Sum only the positive numbers from the set.
        for (int num : unique_nums) {
            if (num > 0) {
                positive_sum += num;
            }
        }
        
        // If the sum is positive, it's our answer.
        // Otherwise, find the largest non-positive number.
        if (positive_sum > 0) {
            return positive_sum;
        } else {
            return *std::max_element(unique_nums.begin(), unique_nums.end());
        }
    }
};