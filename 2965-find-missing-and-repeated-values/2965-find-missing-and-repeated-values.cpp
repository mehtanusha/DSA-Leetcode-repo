class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int missing = 0;
        int repeating = 0;
        int n = grid.size();

       unordered_map<int,int>freq;
        for(auto & row : grid){
            for(int num : row){
                freq[num]++;
            }
        }
        for(int i=1;i<=n*n;i++){
            if(!freq.count(i)){
                missing = i;
            }else if(freq[i] ==2){
                repeating = i;
            }
        }
        return {repeating,missing};
    }
};