class Solution {
public:

    bool isNeg(vector<int>&nums){
        for(int i = 0;i<nums.size();i++){
            if(nums[i]>=0)return false;
        }
        return true;
    }

    int maxSum(vector<int>& nums) {
        int sum = 0;
        int anspos = 0;

        if(isNeg(nums)){
            int ans = INT_MAX;
            for(int i = 0;i<nums.size();i++){
                ans = min(ans,-nums[i]);
            }
            return -ans;
        }

        set<int>sett;
        for(int i = 0;i<nums.size();i++){
            if(nums[i] > 0 && sett.find(nums[i]) == sett.end()){
                anspos = max(anspos,anspos+nums[i]);
                sett.insert(nums[i]);
            }
        }
        return anspos;
    }

};