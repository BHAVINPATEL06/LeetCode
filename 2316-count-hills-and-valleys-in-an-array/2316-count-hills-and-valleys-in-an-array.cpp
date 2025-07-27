class Solution {
public:
    int countHillValley(vector<int>& nums) {
        

        int ans = 0;

        for(int i = 1;i<nums.size()-1;i++){

            int leftClosest = 0;
            int rightClosest = 0;
            int index = i;

            for(int j = index-1;j>=0;j--){
                if(nums[j] == nums[index])break;
                if(nums[j] != nums[index]){
                    leftClosest = nums[j];
                    break;
                }
            }

            for(int j = index+1;j<nums.size();j++){
                if(nums[j] != nums[index]){
                    rightClosest = nums[j];
                    break;
                }
            }

            // cout << leftClosest << " " << rightClosest << endl;
            
            if(leftClosest != 0 && rightClosest != 0 && (nums[index] > leftClosest && nums[index]>rightClosest) || (nums[index]<leftClosest && nums[index]<rightClosest)){
                // cout << nums[index] << " ";
                ans++;
            }

        }
        return ans;
    }
};