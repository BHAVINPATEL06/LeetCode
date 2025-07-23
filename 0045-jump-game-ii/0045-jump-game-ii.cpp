class Solution {
public:

    int solve(vector<int>&nums,int index,vector<int>&dp){
        if(index >= nums.size()-1)return 0;
 
        if(dp[index] != -1) {
            return dp[index];
        }

        int jumps = nums[index];
        int ans = INT_MAX;

        for(int i = 1;i<=jumps;i++){
            if (index + i < nums.size()) {
                int next = solve(nums, index + i,dp);
                if (next != INT_MAX) {
                    ans = min(ans, 1 + next);
                }
            }
        }
        dp[index] = ans;
        return dp[index];
    }

    int jump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return solve(nums,0,dp);
    }
};