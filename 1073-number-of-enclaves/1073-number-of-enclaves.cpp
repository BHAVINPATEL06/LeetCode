class Solution {
public:


    void solve(vector<vector<int>>&grid,int i,int j){
        if(i == grid.size() || j == grid[0].size() || i<0 || j<0)return;
        if(grid[i][j] == 0)return;

        grid[i][j] = 0;

        // solve(grid,i+1,j);  
        // solve(grid,i,j+1);
        // solve(grid,i-1,j);
        // solve(grid,i,j-1);

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}}; 

        for(int d = 0;d<4;d++){
            int newI = i+dirs[d][0];
            int newJ = j+dirs[d][1];

            solve(grid,newI,newJ);
        }

        return;
    }


    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid[0].size();i++){ // First Row // Correct
            if(grid[0][i] == 1){
                solve(grid,0,i);
            }
        }

        int lastCol = grid[0].size()-1;
        for(int i = 0;i<grid.size();i++){ // Last Col // Correct
            if(grid[i][lastCol] == 1){
                solve(grid,i,lastCol);
            }
        }

        for(int i = 0;i<grid.size();i++){ // First Col // Correct
            if(grid[i][0] == 1){
                solve(grid,i,0);
            }
        }
        
        int lastRow = grid.size()-1;

        for(int i = 0;i<grid[0].size();i++){ // Last Row // COrrect
            if(grid[lastRow][i] == 1){
                solve(grid,lastRow,i);
            }
        }

        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1)ans++;
            }
        }
        return ans;
    }
};
