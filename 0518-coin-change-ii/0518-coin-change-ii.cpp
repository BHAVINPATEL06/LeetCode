class Solution {
public:
    // Tere Bhai ne khud se kiya hai....

    // int solve(vector<int>&coins,int amount,int index){
    //     if(index == coins.size())return 0;
    //     if(amount == 0)return 1;
    //     if(amount < 0)return 0;

    //     int ans1 = solve(coins,amount-coins[index],index);
    //     int ans2 = solve(coins,amount,index+1);

    //     cout << ans1 << " " << ans2 << endl;
    //     return ans1+ans2;
    // }

    int solveMem(vector<int>&coins,int amount,int index, vector<vector<int>>&dp){
        if(index == coins.size())return 0;
        if(amount == 0)return 1;
        if(amount < 0)return 0;
        if(dp[index][amount] != -1)return dp[index][amount];

        int ans1 = solveMem(coins,amount-coins[index],index,dp);
        int ans2 = solveMem(coins,amount,index+1,dp);

        dp[index][amount] = ans1+ans2;
        return dp[index][amount];
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        // return solve(coins,amount,0);
        return solveMem(coins,amount,0,dp);
    }
};