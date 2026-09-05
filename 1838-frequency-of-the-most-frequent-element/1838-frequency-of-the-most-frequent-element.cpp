class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());

        int n = nums.size();
        int l =0;
        int r = 0;
        int ans = 1;
        long long windowSum = 0;

        while(r<n){
            windowSum += nums[r];
            long long cost = 1LL * nums[r] * (r-l+1) - windowSum;

            while(cost > k){
                windowSum -= nums[l];
                l++;
                cost = 1LL * nums[r] * (r-l+1) - windowSum;

            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};