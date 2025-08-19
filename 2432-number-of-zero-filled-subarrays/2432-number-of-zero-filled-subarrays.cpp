class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int right = 0;
        long long ans = 0;
        long long count = 0;

        while(right<nums.size()){
            if(nums[right] == 0){
                count++;
                ans+=count;
            }
            else{
                count = 0;
            }
            right++;
        }
        return ans;
    }
};