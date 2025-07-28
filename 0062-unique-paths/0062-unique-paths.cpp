class Solution {
public:

    // int solve(int i,int j,int m,int n){
    //     if(i == m || j == n)return 0;
    //     if(i == m-1 && j == n-1)return 1;

    //     int ans = 0;
    //     ans += solve(i+1,j,m,n);
    //     ans += solve(i,j+1,m,n);

    //     return ans;
    // }


    long long solveTab(int m,int n){
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,0));

        for(int i = 0;i<n;i++){
            dp[m][i] = 1;
        }
        for(int i = 0;i<m;i++){
            dp[0][n] = 1;
        }
        for(int i = m-1;i>=0;i--){
            for(int j = n-1;j>=0;j--){
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[1][0];
    }

    int uniquePaths(int m, int n) {
        
        // return solve(0,0,m,n);
        return (int)solveTab(m,n);
    }
};