class Solution {
public:
    int solve(vector<int>&nums,int target,int index,int sum){
        if(index == nums.size()){
            return sum == target?1:0;
        }

        int inc = solve(nums,target,index+1,sum+nums[index]);
        int exc = solve(nums,target,index+1,sum-nums[index]);

        return inc+exc;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0,0);
    }
};