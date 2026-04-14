class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(), capacity.end(), greater<int>());
        int sum =0;
        int a =0;
        for(int i = 0;i<apple.size();i++){
            sum = sum + apple[i];
        }

        int used = 0;
        int count = 0;

        for (int i = 0; i < capacity.size(); i++) {
            used += capacity[i];
            count++;

            if (used >= sum) {
                return count;
            }
        }
        return count;
    }
};