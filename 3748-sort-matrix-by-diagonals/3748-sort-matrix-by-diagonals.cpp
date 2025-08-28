class Solution {
public:
// Tere bhai ne khud se kiya hai
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        
        for(int i = grid[0].size()-1;i>=0;i--){
            int x = 0;
            int y = i;
            
            int temp1 = 0;
            int temp2 = i;
            vector<int>temp;

            while(x<grid.size()&&y<grid[0].size()){
                temp.push_back(grid[x][y]);
                x++;
                y++;
            }

            sort(temp.begin(),temp.end());
            for(int k = 0;k<temp.size();k++){
                grid[temp1][temp2] = temp[k];
                temp1++;
                temp2++;
            }
        }

        for(int i = 0;i<grid.size();i++){
            int x = i;
            int y = 0;

            int temp1 = i;
            int temp2 = 0;

            vector<int>temp;
            while(x<grid.size() && y<grid[0].size()){
                temp.push_back(grid[x][y]);
                x++;
                y++;
            }

            sort(temp.rbegin(),temp.rend());

            for(int k = 0;k<temp.size();k++){
                grid[temp1][temp2] = temp[k];
                temp1++;
                temp2++;
            }
        }
        return grid;
    }
};