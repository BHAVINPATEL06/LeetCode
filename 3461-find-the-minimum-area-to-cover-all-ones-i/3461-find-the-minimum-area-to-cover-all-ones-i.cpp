class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        pair<int,int>topMost;
        pair<int,int>bottomMost;
        pair<int,int>leftMost;
        pair<int,int>rightMost;

        bool check = false;
        for(int i = 0;i<grid.size();i++){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    topMost = {i,j};
                    check = true;
                    break;
                }
            }
            if(check==true)break;
        }

        check = false;

        for(int i = grid.size()-1;i>=0;i--){
            for(int j = 0;j<grid[0].size();j++){
                if(grid[i][j] == 1){
                    bottomMost = {i,j};
                    check = true;
                    break;
                }
            }
            if(check ==true)break;
        }

        check = false;
        for(int i = 0;i<grid[0].size();i++){
            for(int j = grid.size()-1;j>=0;j--){
                if(grid[j][i] == 1){
                    leftMost = {i,j};
                    check = true;
                    break;
                }
            }
            if(check == true)break;
        }

        check = false;
        for(int i = grid[0].size()-1;i>=0;i--){
            for(int j = grid.size()-1;j>=0;j--){
                if(grid[j][i] == 1){
                    rightMost = {i,j};
                    check = true;
                    break;
                }
            }
            if(check == true)break;
        }

        
        int height = (bottomMost.first-topMost.first)+1;
        int width = (rightMost.first-leftMost.first)+1;
        return height*width;
    }
};