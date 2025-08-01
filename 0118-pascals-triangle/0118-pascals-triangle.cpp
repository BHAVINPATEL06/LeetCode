class Solution {
public:
// Tere bhai ne khud se kiya hai

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int i = 0;i<numRows;i++){
            vector<int>output(i+1);
            for(int j = 0;j<=i;j++){
                if(j == 0 || j == i){
                    output[j] = 1;
                }
                else{
                    output[j] = (ans[i-1][j-1]+ans[i-1][j]);
                }
            }
            ans.push_back(output);
        }
        return ans;
    }
};