class Solution {
public:
    // Gaurang Code
    
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int>row[9];
        unordered_set<int>col[9];
        unordered_set<int>box[9];

        for(int i = 0;i<board.size();i++){
            for(int j = 0;j<board.size();j++){
                if(board[i][j] == '.')continue;

                int boxIndex = (i/3)*3 + j/3;
                
                if(row[i].find(board[i][j]) != row[i].end() ||
                    col[j].find(board[i][j]) != col[j].end() ||
                        box[boxIndex].find(board[i][j]) != box[boxIndex].end())return false;

                row[i].insert(board[i][j]);
                col[j].insert(board[i][j]);
                box[boxIndex].insert(board[i][j]);
            }
        }
        return true;
    }
};