class Solution {
public:

    void solve(vector<vector<int>>&grid,int i,int j){
        if(i == grid.size() || j == grid[0].size() || i<0 || j<0)return;
        if(grid[i][j] == 0)return;

        grid[i][j] = 0;

        solve(grid,i+1,j);
        solve(grid,i,j+1);
        solve(grid,i-1,j);
        solve(grid,i,j-1);

        return;
    }


    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid[0].size();i++){ // First Row // Correct
            // cout << grid[0][i] << " ";
            if(grid[0][i] == 1){
                solve(grid,0,i);
            }
        }

        int lastCol = grid[0].size()-1;
        for(int i = 0;i<grid.size();i++){ // Last Col // Correct
            // cout << grid[i][lastCol] << " ";
            if(grid[i][lastCol] == 1){
                solve(grid,i,lastCol);
            }
        }

        for(int i = 0;i<grid.size();i++){ // First Col // Correct
            // cout << grid[i][0] << " ";
            if(grid[i][0] == 1){
                solve(grid,i,0);
            }
        }
        
        int lastRow = grid.size()-1;

        for(int i = 0;i<grid[0].size();i++){ // Last Row // COrrect
            // cout << grid[lastRow][i] << " ";
            if(grid[lastRow][i] == 1){
                solve(grid,lastRow,i);
            }
        }

        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1)ans++;
                // cout << grid[i][j] << " ";
            }
            // cout << endl;
        }
        return ans;
    }
};