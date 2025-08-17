class Solution {
public:

    int solve(vector<vector<int>>& obstacleGrid,int i,int j,vector<vector<int>>&dp){
        if(i == obstacleGrid.size() || j == obstacleGrid[0].size())return 0;
        if(i == obstacleGrid.size()-1 && j == obstacleGrid[0].size()-1){
            if(obstacleGrid[i][j] == 0){
                 return 1;
            }
        }
        if(dp[i][j] != -1)return dp[i][j];

        int left = 0;
        int down = 0;
        if(obstacleGrid[i][j] == 0){
            obstacleGrid[i][j] = 1;
             left = solve(obstacleGrid,i+1,j,dp);
             down = solve(obstacleGrid,i,j+1,dp);

            obstacleGrid[i][j] = 0;
        }
        

        dp[i][j] = left+down;
        return dp[i][j];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>>dp(obstacleGrid.size()+1,vector<int>(obstacleGrid[0].size()+1,-1));
        return solve(obstacleGrid,0,0,dp);
    }
};