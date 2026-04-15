class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int result = INT_MAX;
        for(int i = 0; i < n; i++){
            if(words[i] == target){
                int dist = min(abs(i - startIndex), n - abs(i - startIndex));
                result = min(result, dist);
            }
        }
        return (result == INT_MAX) ? -1 : result;
    }
};