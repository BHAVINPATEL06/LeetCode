class Solution {
public:

    bool isValid(vector<vector<char>>&board,int i,int j,char k){
        for(int m = 0;m<board.size();m++){
            if(board[m][j] == k)return false;
        }

        for(int m = 0;m<board.size();m++){
            if(board[i][m] == k)return false;
        }
        
        for(int  m= 0;m<board.size();m++){
            if(board[3*(i/3)+m/3][3*(j/3)+m%3] == k)return false;        
        }
        return true;
    }


    bool solve(vector<vector<char>>&board){
        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board.size();j++){
                if(board[i][j] == '.'){
                    for(char k = '1';k<='9';k++){
                        if(isValid(board,i,j,k)){
                            board[i][j] = k;
                            bool ans = solve(board);
                            if(ans)return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};