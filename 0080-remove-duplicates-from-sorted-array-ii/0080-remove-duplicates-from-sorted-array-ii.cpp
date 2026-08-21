class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 2;

        int n = nums.size();
        if(n <=2){
            return n;
        }
        for(int i=2;i<n;i++){
            if(nums[idx - 2] != nums[i]){
                nums[idx] = nums[i];
                idx++;
            }
        }
        return idx;
    }
};