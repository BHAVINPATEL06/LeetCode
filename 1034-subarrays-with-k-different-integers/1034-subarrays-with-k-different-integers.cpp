class Solution {
public:

// Tere bhai ne khud se kiya hai
    int solve(vector<int>&nums,int k){
        int left = 0;
        int right = 0;
        int ans = 0;
        unordered_map<int,int>mapp;

        while(right<nums.size()){
            mapp[nums[right]]++;

            while(mapp.size()>k){
                mapp[nums[left]]--;
                if(mapp[nums[left]] == 0)mapp.erase(nums[left]);
                left++;
            }
            ans += right-left+1;
            right++;
        }
        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans1 = solve(nums,k);
        int ans2 = solve(nums,k-1);
        return ans1-ans2;
    }
};