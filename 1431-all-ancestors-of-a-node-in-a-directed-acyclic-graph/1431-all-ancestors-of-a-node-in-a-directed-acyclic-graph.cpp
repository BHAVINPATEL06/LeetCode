class Solution {
public:
    // Tere bhai ne khud se kiya hai
    // Vishwas nhi hoga liken haa kiya hai
    void solve(int src,unordered_map<int,vector<int>>&adjList,vector<int>&output,vector<bool>&visited){
        visited[src] = true;

        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                output.push_back(nbr);
                solve(nbr,adjList,output,visited);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>ans;
        unordered_map<int,vector<int>>adjList;

        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adjList[v].push_back(u);
        }

        for(int i = 0;i<n;i++){
            vector<int>output;
            vector<bool>visited(n,false);
            solve(i,adjList,output,visited);
            sort(output.begin(),output.end());
            ans.push_back(output);
        }
        return ans;
    }
};