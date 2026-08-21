class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n =  nums.size();

        int idx = 0;
        int cnt = 1;
        for(int i=1;i<n;i++){
            if(nums[idx] != nums[i]){
                nums[++idx] = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};