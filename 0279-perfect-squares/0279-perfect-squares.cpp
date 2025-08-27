class Solution {
public:

    int solveUsingRec(int n){
        // base case
        if(n<=0)return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 3;

        int ans = INT_MAX;
        int count = 0;

        for(int i = 1;i<n;i++){
            int square = i*i;
            // square ki value hamesha choti raheni chaiye number se
            if(square <= n){
                int newn = n-square;
                count = 1 + solveUsingRec(newn);
            }
            ans = min(ans,count);

        }
        return ans;
    }

    // 1D dp ka q hai

    int solveUsingMem(int n,vector<int>&dp){
        // base case
        if(n<=0)return 0;
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 3;

        if(dp[n] != -1){
            return dp[n];
        }

        int ans = INT_MAX;
        int count = 0;

        for(int i = 1;i<n;i++){
            int square = i*i;
            // square ki value hamesha choti raheni chaiye number se
            if(square <= n){
                int newn = n-square;
                count = 1 + solveUsingMem(newn,dp);
            }
            ans = min(ans,count);

        }
        dp[n] = ans;
        return dp[n];
    }

    int numSquares(int n) {
        vector<int>dp(n+1,-1);
        //  return solveUsingRec(n);
        return solveUsingMem(n,dp);
    }
};