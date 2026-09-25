class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || numRows >= s.size()){
            return s;
        }

        vector<string>rows(numRows);

        int currentrow = 0;
        int direction = 1;

        for(char ch : s){
            rows[currentrow] += ch;
            if(currentrow == 0){
                direction = 1;
            }
            if(currentrow == numRows - 1){
                direction = -1;
            }
            currentrow += direction;
        }

        string ans = "";

        for (string row : rows) {
            ans += row;
        }

        return ans;
    }
};