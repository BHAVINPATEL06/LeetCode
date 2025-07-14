class Solution {
public:

    long long countSubarrays(vector<int>& nums, long long k) {
        int left = 0;
        int right = 0;
        long long ans = 0;
        long long sum = 0;

        while(right<nums.size()){
            sum += nums[right];

            while((long long)sum*(right-left+1)>=k){
                sum -= nums[left];
                left++;
            }
            
            ans += right-left+1;
            right++;
        }
        return ans;
    }
};
