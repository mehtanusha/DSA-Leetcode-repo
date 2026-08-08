class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=1;i<=9;i++){
            vector<bool> row(10,false), col(10,false);

            for(int j=1;j<=9;j++){

                char r = board[i-1][j-1];
                char c = board[j-1][i-1];

                if(r != '.'){
                    if(row[r-'0']) return false;
                    row[r-'0'] = true;
                }

                if(c != '.'){
                    if(col[c-'0']) return false;
                    col[c-'0'] = true;
                }
            }
        }

        for(int rowstart = 0;rowstart<9;rowstart+=3){
            for(int colstart = 0;colstart<9;colstart+=3){
              vector<bool> box(10,false);

              for(int i = rowstart;i<rowstart+3;i++){
                for(int j = colstart;j<colstart+3;j++){
                    if(board[i][j]=='.'){
                        continue;
                    }

                    char num = board[i][j];
                    if(box[num-'0']) return false;
                    box[num-'0'] = true;
                }
              }
            }
        }
        return true;
    }
};