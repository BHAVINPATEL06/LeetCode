class Solution {
public:

    int solve(vector<vector<int>>&triangle,int i,int j,vector<vector<int>>&dp){
        if(i == triangle.size() || j == triangle[i].size())return 0;
        if(i == triangle.size()-1)return triangle[i][j];
        if(dp[i][j]!=-1)return dp[i][j];

        int right = solve(triangle,i+1,j+1,dp);
        int same = solve(triangle,i+1,j,dp);
        dp[i][j]= min(right,same)+triangle[i][j];
        return dp[i][j];
    }

    int solveTab(vector<vector<int>>&triangle){
        int n = triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,0));

        // base case chalaya hai
        for(int i = 0;i<n;i++){
            dp[n-1][i] = triangle[n-1][i];
        }

        // Main Logic
        for(int i = triangle.size()-2;i>=0;i--){
            for(int j= 0;j<=i;j++){                       // Pura code sahi likha tha bass ye wala loop 0 -> i chalana tha ye nhi samjha 
                dp[i][j] = min(dp[i+1][j+1],dp[i+1][j])+triangle[i][j];
            }
        }
        return dp[0][0];
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        // int n = triangle.size();
        // int m = triangle[triangle.size()-1].size();
        // // cout << n << " " << m << endl;
        // vector<vector<int>>dp(triangle.size()+1,vector<int>(triangle[triangle.size()-1].size()+1,-1));
        // return solve(triangle,0,0,dp);
        return solveTab(triangle);
    }
};