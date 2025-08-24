class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {

        unordered_map<int,int>mapp;
        for(int i = 0;i<nums.size();i++){
            mapp[nums[i]]++;
        }

        for(auto a:mapp){
            if(a.second > nums.size()/k)return false;
            // cout << a.first << " " << a.second << endl;
        }
        // cout << nums.size() << endl;
        
        int maxGrpscamForm = nums.size()/k;
        if(maxGrpscamForm*k != nums.size())return false;
        if(maxGrpscamForm*mapp.size()%k == 0)return true;

        return true;
    }
};