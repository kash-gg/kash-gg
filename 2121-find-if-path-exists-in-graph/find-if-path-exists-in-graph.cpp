class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source == destination) return true;
        
        // Build adjacency list
        unordered_map<int, vector<int>> graph;
        for(auto& edge : edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // Use set for visited tracking
        set<int> seen;
        
        return dfs(graph, seen, source, destination);
    }
    
private:
    bool dfs(unordered_map<int, vector<int>>& graph, set<int>& seen, 
             int current, int destination) {
        if (current == destination) return true;
        
        seen.insert(current);  // Mark as visited
        
        // Check all neighbors of current node
        for(auto& neighbor : graph[current]) {
            if(seen.find(neighbor) == seen.end()) {  // If not visited
                if (dfs(graph, seen, neighbor, destination)) {
                    return true;
                }
            }
        }
        return false;
    }
};
