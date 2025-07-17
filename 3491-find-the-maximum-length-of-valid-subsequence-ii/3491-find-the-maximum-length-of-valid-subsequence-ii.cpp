#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(k, -1));
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                res = max(res, 1 + go(dp, nums, j, k, (nums[i] + nums[j]) % k));
            }
        }
        return res;
    }
    
    static int go(vector<vector<int>>& dp, vector<int>& nums, int i, int k, int rem) {
        if (dp[i][rem] != -1) {
            return dp[i][rem];
        }
        
        int res = 1;
        for (int j = i + 1; j < nums.size(); ++j) {
            if ((nums[j] + nums[i]) % k == rem) {
                res += go(dp, nums, j, k, rem);
                break;
            }
        }
       dp[i][rem] = res;
       return dp[i][rem];
    }
};