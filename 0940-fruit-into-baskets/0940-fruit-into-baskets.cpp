class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mapp;
        int k = 2;
        int left = 0;
        int right = 0;
        int ans = 0;

        while(right<fruits.size()){
            mapp[fruits[right]]++;

            while(mapp.size()>2){
                mapp[fruits[left]]--;
                if(mapp[fruits[left]] == 0)mapp.erase(fruits[left]);
                left++;
            }
            right++;
            ans = max(ans,right-left);
        }
        return ans;
    }
};