class Solution {
public:

    void checkIsValid(vector<vector<int>>&grid,int i,int j,long long &sum){
        if(i == grid.size() || j == grid[0].size() || j<0 || i<0)return;
        if(grid[i][j] == 0)return;

        sum += grid[i][j];
        grid[i][j] = 0;

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int d = 0;d<4;d++){
            int newI = i + dirs[d][0];
            int newY = j + dirs[d][1];

            checkIsValid(grid,newI,newY,sum);
        }
        return;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int ans = 0;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j]>0){
                    long long sum = 0;
                    checkIsValid(grid,i,j,sum);
                    if(sum%k == 0)ans++;
                }
            }
        }
        return ans;
    }
};