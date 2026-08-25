class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st;
        int n = nums.size();

        for(int x : nums){
            st.insert(x);
        }
        for(int i=1;i<=n+1;i++){
            if(st.find(i*k) == st.end()){
                return i*k;
            }
        }
        return k;
    }
};