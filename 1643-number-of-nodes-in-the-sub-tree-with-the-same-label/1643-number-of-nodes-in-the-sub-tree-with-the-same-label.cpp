class Solution {
public:
    vector<int> dfs(int node, int parent, vector<vector<int>>& adj, string& labels, vector<int>& result) {
        // Count of each character in current subtree
        vector<int> count(26, 0);
        
        // Count current node's label
        count[labels[node] - 'a']++;
        
        // Visit all children
        for (int child : adj[node]) {
            if (child != parent) {
                vector<int> childCount = dfs(child, node, adj, labels, result);
                // Merge child counts into current subtree count
                for (int i = 0; i < 26; i++) {
                    count[i] += childCount[i];
                }
            }
        }
        
        // Store result for current node
        result[node] = count[labels[node] - 'a'];
        
        return count;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        
        // Build adjacency list (bidirectional since it's a tree)
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> result(n);
        dfs(0, -1, adj, labels, result);
        
        return result;
    }
};