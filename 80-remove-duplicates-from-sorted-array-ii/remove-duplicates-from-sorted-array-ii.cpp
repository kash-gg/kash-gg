class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();
        
        int left = 2;  // Position for next valid element
        
        for (int right = 2; right < nums.size(); right++) {
            // Check if current element is different from element 2 positions back
            if (nums[right] != nums[left - 2]) {
                nums[left] = nums[right];
                left++;
            }
        }
        
        return left;
    }
};
