class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans = 0;
        int sum = 0;
        int l = 0;
        int r = 0;
        int count_zeroes = 0;

        while(r<n){
           sum = sum + nums[r];
           while(l<r && (nums[l] == 0 || sum > goal)){
                if(nums[l] == 0){
                    count_zeroes++;
                }else{
                    count_zeroes = 0;
                }
                sum =  sum - nums[l];
                l++;
           }

           if(sum == goal){
            ans = ans + count_zeroes +1 ;
           }
           r++;
        }
        return ans;
    }
};