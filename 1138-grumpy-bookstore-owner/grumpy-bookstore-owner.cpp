class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        
        // Step 1: already satisfied customers
        int baseSatisfied = 0;
        for (int i = 0; i < n; i++) {
            if (grumpy[i] == 0) {
                baseSatisfied += customers[i];
            }
        }
        
        // Step 2: sliding window to find max extra customers
        int extra = 0, maxExtra = 0;
        
        // initial window
        for (int i = 0; i < minutes; i++) {
            if (grumpy[i] == 1) {
                extra += customers[i];
            }
        }
        
        maxExtra = extra;
        
        // slide the window
        for (int i = minutes; i < n; i++) {
            // add next
            if (grumpy[i] == 1) {
                extra += customers[i];
            }
            
            // remove previous
            if (grumpy[i - minutes] == 1) {
                extra -= customers[i - minutes];
            }
            
            maxExtra = max(maxExtra, extra);
        }
        
        return baseSatisfied + maxExtra;
    }
};