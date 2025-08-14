class Solution {
public:
    int mod = 1e9+7;

    int solve(int m,int n,int maxMove,int i,int j,vector<vector<vector<int>>>&dp){
        if(maxMove < 0)return 0;
        if(i<0 || j<0 || i == m || j == n)return maxMove >= 0?1:0;
        if(dp[maxMove][i][j] != -1)return dp[maxMove][i][j]%mod;
        
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        int ans = 0;
        for(int d = 0;d<4;d++){
            int newX = i + dirs[d][0];
            int newY = j + dirs[d][1];

            ans = ans%mod + (solve(m,n,maxMove-1,newX,newY,dp)%mod);
        }
        dp[maxMove][i][j] = ans%mod;
        return dp[maxMove][i][j]%mod;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>>dp(maxMove+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(m,n,maxMove,startRow,startColumn,dp);
    }
};