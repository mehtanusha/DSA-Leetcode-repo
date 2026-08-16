class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long,int>freq;

        for(auto &row : wall){
            long long gap = 0;
            for(int j=0;j<row.size()-1;j++){
                gap = gap + row[j];
                freq[gap]++;
            }
        }
        int maxgap = 0;
        for(auto &it : freq){
            maxgap = max(maxgap,it.second);
        }
        return wall.size() - maxgap;
    }
};