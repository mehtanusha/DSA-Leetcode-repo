class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2 == 0){
                freq[nums[i]]++;
            }
        }
        int ans = -1;
        int maxfreq = INT_MIN;
        for(auto &it : freq){
            if(it.second > maxfreq){
                maxfreq = it.second;
                ans = it.first;
            }
            else if(it.second == maxfreq){
                ans = min(it.first,ans);
            }
        }
        return ans;
    }
};