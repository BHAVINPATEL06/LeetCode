class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>ans;
        for(int i = 0;i<rowIndex+1;i++){
            vector<int>temp(i+1);
            for(int j = 0;j<=i;j++){
                if(i == j || j == 0){
                    temp[j] = 1;
                }
                else{
                    temp[j] = ans[j]+ans[j-1];
                }
            }
            ans = temp;
        }
        return ans;
    }
};