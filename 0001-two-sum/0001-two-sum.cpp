class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>>map;
        //value to indexes store

        for(int i = 0;i<nums.size();i++){
            int val = nums[i];
            map[val].push_back(i);
        }
        //ab humne har value k hr possible index ki mapping store kar li hai

        for(int i = 0;i<nums.size();i++){
            int curr = nums[i];
            int req = target - curr;

            if(map.find(req) != map.end()){


                if(req == curr && map[curr].size() == 1){
                    continue;
                }
                if(req == curr && map[curr].size() > 1){
                    return{map[curr][0],map[req][1]};
                }
                else{
                    return {i,map[req][0]};
                }
            }
        }
        return{-1,-1};
    }
};