class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int range = n/3;
        
        vector<int>ans;
        unordered_map<int,int>freq;
        for(int num : nums){
            freq[num]++;
        }
        for(auto &it : freq){
            if(it.second > range){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};