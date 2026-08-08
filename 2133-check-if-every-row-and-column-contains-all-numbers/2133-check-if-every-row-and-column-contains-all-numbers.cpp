class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
    
        for(int i=1;i<=n;i++){
            vector<bool>row(n+1,false),col(n+1,false);
            for(int j=1;j<=n;j++){
                int r = matrix[i-1][j-1];
                int c = matrix[j-1][i-1];
                if(r>n || c>n || row[r]|| col[c]) return false;
                row[r] = true;
                col[c] = true;
            }
        }
        return true;
    }
};