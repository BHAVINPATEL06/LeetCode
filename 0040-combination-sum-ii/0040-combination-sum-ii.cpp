class Solution {
public:

    void solve(vector<vector<int>>&ans,vector<int>& candidates,int target,int index,  vector<int>&semians){
        if(target == 0){
            ans.push_back(semians);
            return;
        }
        if(target<0){
            return;
        }

        for(int i = index;i<candidates.size();i++){
            if(i>index && candidates[i] == candidates[i-1]){
                continue;
            }

            semians.push_back(candidates[i]);
            solve(ans,candidates,target-candidates[i],i+1,semians);
            semians.pop_back();
        }
        
    }


    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>semians;
        solve(ans,candidates,target,0,semians);
        return ans;
    }
};