class Solution {
public:
    // te
    int solve(vector<int>&nums,int index,int size,vector<int>&dp){
        if(index>=size)return 0;
        if(dp[index] != -1)return dp[index];

        int inc = nums[index]+solve(nums,index+2,size,dp);
        int exc = solve(nums,index+1,size,dp);

        dp[index]= max(inc,exc);
        return dp[index];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)return nums[0];
        vector<int>dp(nums.size(),-1);
        vector<int>dp2(nums.size(),-1);
        int ans1 = solve(nums,0,nums.size()-1,dp);
        int ans2 = solve(nums,1,nums.size(),dp2);
        return max(ans1,ans2);
    }
};