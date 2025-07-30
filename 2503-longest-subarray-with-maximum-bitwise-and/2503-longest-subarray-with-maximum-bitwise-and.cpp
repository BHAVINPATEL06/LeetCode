class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxiAND  = INT_MIN;
        for(int i = 0;i<nums.size();i++){
            maxiAND = max(nums[i],maxiAND);
        }

        int right = 0;
        int left = 0;
        int ans = 0;

        while(right<nums.size()){

            if(nums[right] == maxiAND){
                ans = max(ans,right-left+1);
                right++;
            }
            else{
                right++;
                left = right;
            }
        }
        return ans;
    }
};