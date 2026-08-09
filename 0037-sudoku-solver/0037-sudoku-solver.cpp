class Solution {
public:
    bool isvalid(int row,int col ,int digit,vector<vector<char>>& board){
       for(int i=0;i<9;i++){
        if(board[i][col] == digit) return false;
        if(board[row][i] == digit) return false;
       }
       int start_i = (row/3)*3;
       int start_j = (col/3)*3;

       for(int k=0;k<3;k++){
        for(int l=0;l<3;l++){
            if(board[start_i + k][start_j + l] == digit){
                return false;
            }
        }
       }
       return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    for(char d='1';d<='9';d++){
                        if(isvalid(i,j,d,board)){
                            board[i][j] = d;
                            if(solve(board)) return true;
                            board[i][j] = '.';
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