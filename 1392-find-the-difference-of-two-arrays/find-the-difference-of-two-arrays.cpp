class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> a(nums1.begin(), nums1.end());
        set<int> b(nums2.begin(), nums2.end());

        vector<int> x,y;
        for( int num : a){
            if(b.find(num) == b.end()){
                x.push_back(num);
            }
        }

        for(int num :b){
            if(a.find(num) == a.end()){
                y.push_back(num);
            }
        }
        return {x,y};
    }
};