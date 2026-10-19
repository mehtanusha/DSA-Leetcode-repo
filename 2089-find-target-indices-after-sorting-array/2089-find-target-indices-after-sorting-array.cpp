class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int count = 0;
        int anscnt = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] < target){
                count++;
            }
            if(nums[i] == target){
                anscnt++;
            }
        }
        vector<int>ans;
        for(int i=0;i<anscnt;i++){
            ans.push_back(count);
            count++;
        }
        return ans;
    }
};