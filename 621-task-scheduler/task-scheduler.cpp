#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count frequency of each task
        unordered_map<char, int> taskCount;
        for (char task : tasks) {
            taskCount[task]++;
        }
        
        // Create max heap using priority queue
        priority_queue<int> maxHeap;
        for (auto& pair : taskCount) {
            maxHeap.push(pair.second);
        }
        
        int time = 0;
        
        while (!maxHeap.empty()) {
            vector<int> temp;
            
            // Try to schedule tasks for the next n+1 intervals
            for (int i = 0; i <= n; i++) {
                if (!maxHeap.empty()) {
                    int freq = maxHeap.top();
                    maxHeap.pop();
                    
                    // If there are more instances of this task, save for later
                    if (freq > 1) {
                        temp.push_back(freq - 1);
                    }
                }
                
                time++;
                
                // If no more tasks, we're done
                if (maxHeap.empty() && temp.empty()) {
                    break;
                }
            }
            
            // Put remaining tasks back in heap
            for (int freq : temp) {
                maxHeap.push(freq);
            }
        }
        
        return time;
    }
};
