class NumMatrix {
public:
    vector<vector<int>>prefix;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        //extra row of 0
        prefix.push_back(vector<int>(cols +1,0));

        for(int i=0;i<rows;i++){
            vector<int>row;

            row.push_back(0);
            for(int j=0;j<cols;j++){
                int curr = matrix[i][j] + prefix[i][j+1] + row[j] - prefix[i][j];

                row.push_back(curr);
            }
            prefix.push_back(row);
        }


    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        //whole - top - left + overlap
        return prefix[row2+1][col2+1] - prefix[row1][col2 + 1] - prefix[row2 +1][col1] + prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */