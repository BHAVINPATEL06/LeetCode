class Solution {
public:

    int solve(string &text1,string &text2,int i,int j,vector<vector<int>>&dp){
        if(i == text1.length())return 0;
        if(j < 0)return 0;
        if(dp[i][j] != -1)return dp[i][j];

        int inc = 0;
        if(text1[i] == text2[j]){
            inc = 1+solve(text1,text2,i+1,j-1,dp);
        }
        else{
         inc = max(solve(text1,text2,i,j-1,dp),solve(text1,text2,i+1,j,dp));
        }
        dp[i][j] =  inc;
        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        int j = s.length()-1;
        vector<vector<int>>dp(s.length()+1,vector<int>(s.length()+1,-1));
        return solve(s, s, 0, j,dp);
    }
};