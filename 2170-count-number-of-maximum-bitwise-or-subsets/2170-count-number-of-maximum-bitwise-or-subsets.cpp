class Solution {
public:
    void solve(vector<int>& nums, int index, unordered_map<int, int>& mapp,
               int ORR) {
        int inc = 0;
        int exc = 0;
        if (index == nums.size()) {
            mapp[ORR]++;
            return;
        }

        // Temporary Variable ka use isliye kiya kyuki ORR kari hui value bass
        // include mai jaaye Exclude karke time nhi daalni OR value isliye
        // exclude vale parameter mai without OR wala bhej diya
        int temp = 0;
        temp = ORR | nums[index];
        solve(nums, index + 1, mapp, temp);
        solve(nums, index + 1, mapp, ORR);

        return;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int, int> mapp;
        solve(nums, 0, mapp, 0);
        int maxi = INT_MIN;
        for (auto a : mapp) {
            maxi = max(maxi, a.first);
        }
        return mapp[maxi];
    }
};