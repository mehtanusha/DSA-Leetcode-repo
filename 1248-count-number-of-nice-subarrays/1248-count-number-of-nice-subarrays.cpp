class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int sum = 0;
        int zerocount = 0;
        int ans = 0;

        while(r<n){
            if(nums[r] % 2 == 0){
                nums[r] = 0;
            }else{
                nums[r] = 1;
            }

            sum = sum + nums[r];
            while(l<r && (nums[l] == 0 || sum > k)){
                if(nums[l] == 0){
                    zerocount++;
                }else{
                    zerocount = 0;
                    sum = sum - nums[l];
                }
                l++;
            }
            if(sum == k){
                ans = ans + 1 + zerocount;
            }
            r++;
        }
        return ans;
    }
};