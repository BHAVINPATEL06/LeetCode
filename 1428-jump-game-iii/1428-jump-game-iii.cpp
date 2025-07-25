class Solution {
public:

    bool solve(vector<int>&arr,int start,vector<bool>&visited){
        if(start >= arr.size() || start<0)return false;
        if(arr[start] == 0)return true;


        bool ans = false;
        if(visited[start] == false){
            visited[start] = true;
            ans = false || solve(arr,start+arr[start],visited) || solve(arr,start-arr[start],visited);
            visited[start] = false;
        }
        return ans;
    }

    bool canReach(vector<int>& arr, int start) {
        vector<bool>visited(arr.size(),false);
        return solve(arr,start,visited);
    }
};