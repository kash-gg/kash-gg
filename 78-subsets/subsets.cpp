#include <vector> // Make sure to include this header

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result; 
        result.push_back({});

        for (int num : nums) {
            int currentSize = result.size();
             for (int i = 0; i < currentSize; ++i) {
                // 1. Get the current subset (result[i])
                std::vector<int> newSubset = result[i];

                // 2. Add 'num' to this new subset
                newSubset.push_back(num);

                // 3. Add the newly created subset to the 'result' list
                result.push_back(newSubset);
            }
        }
        return result;
    }
};