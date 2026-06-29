class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int>mp;
        int sum =0;
        mp[0] = 1;

        for(int i=0;i<n;i++){
            sum = sum + nums[i];
            if(mp.find(sum-goal) != mp.end()){
                ans = ans + mp[sum-goal];
            }
            mp[sum]++;
        }
        return ans;
    }
};