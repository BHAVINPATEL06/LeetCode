class Solution {
public:

    long long int mod = 1e9+7;
    int solve(int n,int x,int index,vector<vector<int>>&dp){
        if(n < 0)return 0;
        if(n == 0)return 1;
        if(pow(index,x)>n)return 0;
        if(dp[n][index] != -1)return dp[n][index];

        dp[n][index] = (solve(n-pow(index,x),x,index+1,dp)%mod+ solve(n,x,index+1,dp)%mod)%mod;
        return dp[n][index]%mod;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(n,x,1,dp);
    }
};