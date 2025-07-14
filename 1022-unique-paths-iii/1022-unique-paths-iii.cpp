class Solution {
public:


    bool isSafe(vector<vector<int>>&grid){
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 2)continue;
                if(grid[i][j] != -1)return false;
            }
        }
        return true;
    }

    int ans = 0;
    int solve(vector<vector<int>>&grid,int i,int j){
        if(i == grid.size() || j == grid[0].size()||i<0||j<0)return 0;
        if(grid[i][j] == 2 && isSafe(grid)){
            ans++;
            return ans;
        }

        if(grid[i][j] == 0 || grid[i][j] == 1){
            grid[i][j] = -1;
            solve(grid,i+1,j);
            solve(grid,i,j+1);
            solve(grid,i-1,j);
            solve(grid,i,j-1);

            grid[i][j] = 0;
        }
        return ans;
    }


    int uniquePathsIII(vector<vector<int>>& grid) {
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    return solve(grid,i,j);
                }
            }
        }
        return -1;
    }
};
