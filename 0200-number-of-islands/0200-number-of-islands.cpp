class Solution {
public:

    void solve(vector<vector<char>>&grid,int i,int j){
        if(i == grid.size() || j == grid[0].size() || i<0 || j<0)return;

        if(grid[i][j] == '1'){
            grid[i][j] = '0';
            int dirs[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
            for(int d= 0;d<4;d++){
                int newX = i + dirs[d][0];
                int newY = j + dirs[d][1];

                solve(grid,newX,newY);
            }
        }
        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == '1'){
                    ans++;
                    solve(grid,i,j);
                }
            }
        }
        return ans;
    }
};