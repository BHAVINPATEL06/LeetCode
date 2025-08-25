class Solution {
public:
// Tere bhai ne khud se kiya hai
// Vishwas nhi hoga liken kar diya
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        vector<int>ans;
        int count = 0;

        for(int i = 0;i<mat.size();i++){
            int x = i+1;
            int j = 0;
            vector<int>temp;
            while(j<=mat[0].size()-1 && x > 0 ){
                temp.push_back(mat[x-1][j]);
                x--;
                j++;
            }
            if(count&1)reverse(temp.begin(),temp.end());
            for(int k = 0;k<temp.size();k++){
                ans.push_back(temp[k]);
            }
            count++;
        }

        for(int i = 1;i<mat[0].size();i++){
            int x = mat.size();
            int j = i;
            vector<int>temp;
        
            while(j<=mat[0].size()-1 && x > 0){
                temp.push_back(mat[x-1][j]);
                x--;
                j++;
            }
            if(count&1)reverse(temp.begin(),temp.end());
            for(int k = 0;k<temp.size();k++){
                ans.push_back(temp[k]);
            }
            count++;
        }

        return ans;
    }
};