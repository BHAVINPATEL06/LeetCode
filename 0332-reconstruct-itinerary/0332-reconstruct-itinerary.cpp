class Solution {
public:

    void solve(string src,unordered_map<string,vector<string>>&adjList,vector<string>&ans){
        // Tere bhai ka ye logic tha but neeche wala socha tha maine but back kaise ko kaise access
        // kare vo nhi pata lag rha tha but baaki toh chal gya tha

        // if(src == "#")return;
        // ans.push_back(src);
        // for(auto nbr:adjList[src]){
        //     if(nbr != "#"){
        //         string temp = nbr;
        //         for(int i= 0;i<adjList[src].size();i++){
        //             if(nbr == adjList[src][i]){
        //                 adjList[src][i] = "#";
        //             }
        //         }
        //         solve(temp,adjList,ans);
        //     }
        // }
        // return;

        while(!adjList[src].empty()){
            string next = adjList[src].back();
            adjList[src].pop_back();
            solve(next,adjList,ans);
        }
        ans.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,vector<string>>adjList;
        vector<string>ans;

        for(int i = 0;i<tickets.size();i++){
            string u = tickets[i][0];
            string v = tickets[i][1];

            adjList[u].push_back(v);
            sort(adjList[u].rbegin(),adjList[u].rend());
        }


        for(auto a:adjList){
            if(a.first == "JFK"){
                solve(a.first,adjList,ans);
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};