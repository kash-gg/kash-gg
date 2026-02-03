class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> a;
        vector<int> result;

        for(auto x:nums1){
            a[x]++;
        }

        for(int i =0;i<nums2.size(); i++){
            if(a[nums2[i]]> 0){
                result.push_back(nums2[i]);
                a[nums2[i]]--;
            }
        }
        return result;
    }
};