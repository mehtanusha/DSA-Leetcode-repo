class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        int sum = nums[0];
        int ans = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] != nums[i-1] + 1){
               break;
            }
            sum = sum + nums[i];
        }
        unordered_set<int>st(nums.begin(),nums.end());

        while(st.count(sum)){
            sum++;
        }
        return sum;
    }
};