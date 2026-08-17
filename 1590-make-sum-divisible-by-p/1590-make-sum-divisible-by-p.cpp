class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int>mp;

        int totalSum = 0;
        for (int num : nums) {
            totalSum = (totalSum + num) % p;
        }
        int target = totalSum % p;
        if(target == 0){
            return 0;
        }
        int n = nums.size();
        mp[0]  =-1;
        int curr = 0;
        int ans  = n;
        for(int i=0; i<n;i++){
            curr = (curr + nums[i]) % p;

            int prev = (curr - target + p) % p;

            if(mp.find(prev) != mp.end()){
                int length = i - mp[prev];
                ans = min(ans,length);
            }
            mp[curr] = i;
        }
        return ans == n ? -1 : ans;
    }
};