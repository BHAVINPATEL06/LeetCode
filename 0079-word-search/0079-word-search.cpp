class Solution {
public:

    bool solve(vector<vector<char>>&board,string word,int index,int i,int j){
        if(index == word.length())return true;
        if(i == board.size() || j == board[0].size() || i < 0 || j<0)return false;

        if(board[i][j] == word[index]){
            board[i][j] = '$';
            int dirs[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
            for(int d = 0;d<4;d++){
                int newX = i + dirs[d][0];
                int newY = j + dirs[d][1];
                if(solve(board,word,index+1,newX,newY))return true;
            }
            board[i][j] = word[index];
        }
    return false;
    }

    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    if(solve(board,word,0,i,j))return true;
                }
            }
        }
        return false;
    }
};