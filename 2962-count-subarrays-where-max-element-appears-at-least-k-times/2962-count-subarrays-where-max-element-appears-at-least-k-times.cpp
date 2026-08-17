class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int maxelement = *max_element(nums.begin(), nums.end());

        long long ans = 0;
        int cnt = 0;
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {

            if (nums[j] == maxelement) {
                cnt++;
            }

            while (cnt >= k) {

                if (nums[i] == maxelement) {
                    cnt--;
                }

                i++;
            }

            ans += i;
        }

        return ans;
    }
};