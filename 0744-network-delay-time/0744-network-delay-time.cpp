class Solution {
public:

    void solve(int src,unordered_map<int,vector<pair<int,int>>>&adjList,vector<int>&dist){
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,src});

        while(!pq.empty()){
            auto front = pq.top();
            pq.pop();

            int u = front[1];

            for(auto nbr:adjList[u]){
                int v = nbr.first;
                int wt = nbr.second;

                if(dist[v]>dist[u]+wt){
                    dist[v] = dist[u]+wt;
                    pq.push({dist[v],v});
                }
            }
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>>adjList;

        for(int i = 0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int wt = times[i][2];

            adjList[u].push_back({v,wt});
            // adjList[v].push_back({u,wt});
        }

        vector<int>dist(n+1,INT_MAX);
        dist[k] = 0;
        solve(k,adjList,dist);
        int ans = INT_MIN;

        for(int i = 1;i<dist.size();i++){
            ans = max(ans,dist[i]);
            cout << dist[i] << " ";
        }

        return ans == INT_MAX?-1:ans;
    }
};