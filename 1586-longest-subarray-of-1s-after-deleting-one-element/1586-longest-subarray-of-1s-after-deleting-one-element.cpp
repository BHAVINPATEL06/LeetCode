class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int ans = 0;
        int k = 1;

        while(right<nums.size()){
            if(nums[right] == 0)k--;

            while(k<0){
                if(nums[left] == 0)k++;
                left++;
            }

            ans = max(ans,right-left);
            right++;
        }
        return ans;
    }
};