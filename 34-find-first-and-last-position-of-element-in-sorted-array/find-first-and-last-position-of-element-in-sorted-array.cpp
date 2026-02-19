class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int n = nums.size();
        if (n == 0) return {-1, -1};
        int first = -1;
        int last = -1;

        vector<int> result;

        while(low<=high){
          
            int mid = low + (high - low)/2;

            if(nums[mid] >= target){
                if (nums[mid] == target) first = mid;
                high = mid - 1;
            }

            else{
                low = mid + 1;
            }
        }

        low = 0;
        high = n -1;

        while(low<=high){
            int mid = low + (high - low)/2;

            if(nums[mid] <= target){
                if (nums[mid] == target) last = mid;
                low = mid + 1;
            }

            else{
                high = mid - 1;
            }
        }
        return {first,last};
    }
};