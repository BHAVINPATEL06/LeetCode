class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int ans = 0;
        unordered_map<int,int>mapp;

        while(right<nums.size()){
            mapp[nums[right]]++;

            while(mapp[nums[right]]>k){
                mapp[nums[left]]--;
                if(mapp[nums[left]] == 0)mapp.erase(nums[left]);
                left++;
            }

            ans = max(ans,right-left);
            right++;
        }
        return ans+1;
    }
};