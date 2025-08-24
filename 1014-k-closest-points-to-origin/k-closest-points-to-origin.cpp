class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // Max heap of size k - largest distances at top
        priority_queue<pair<int, vector<int>>> maxHeap;
        for (vector<int>& point : points) {
            int distance = point[0] * point[0] + point[1] * point[1];
            if (maxHeap.size() < k) {
                // If heap not full, just add the point
                maxHeap.push({distance, point});
            } else if (distance < maxHeap.top().first) {
                // If current point is closer than the farthest point in heap
                maxHeap.pop();                   // Remove the farthest point
                maxHeap.push({distance, point}); // Add current closer point
            }
        }
       vector<vector<int>> result;
        while (!maxHeap.empty()) {
            result.push_back(maxHeap.top().second);  // .second is the point
            maxHeap.pop();
        }
        return result; 
    }
};