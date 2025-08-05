class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        vector<bool>visited(fruits.size(),false);
        int ans = 0;

        for(int i = 0;i<fruits.size();i++){
            int fruit = fruits[i];
            bool check = false;

            for(int j = 0;j<baskets.size();j++){
                if(baskets[j]>=fruit && visited[j] == false){
                    visited[j] = true;
                    check = true;
                    break;
                }
            }
            if(!check)ans++;
        }
        return ans;
    }
};