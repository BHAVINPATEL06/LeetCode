class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        vector<int> lastPos(32, -1);

        // Traverse from right to left
        for (int i = n-1; i >= 0; --i) {
            // Mark last position for bits set in nums[i]
            for (int b = 0; b < 32; ++b) {
                if (nums[i] & (1 << b)) {
                    lastPos[b] = i;
                }
            }
            // Find the furthest position of any bit set in max OR from here
            int far = i;
            for (int b = 0; b < 32; ++b) {
                far = max(far, lastPos[b]);
            }
            ans[i] = far - i + 1; // minimum length (could be 1)
        }

        return ans;
    }
};
