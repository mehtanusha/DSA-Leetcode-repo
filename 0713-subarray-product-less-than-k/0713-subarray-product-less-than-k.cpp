class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        int left = 0;
        long long product = 1;
        int ans = 0;
        int right = 0;
        int n = nums.size();

        while(right < n) {

            product *= nums[right];

            while (product >= k && left <= right) {
                product /= nums[left];
                left++;
            }

            ans += right - left + 1;
            right++;
        }

        return ans;
    }
};