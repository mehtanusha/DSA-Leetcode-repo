class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n =nums.size();
        
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        

        vector<vector<int>>bucket(n+1);
        for(auto it : freq){
            bucket[it.second].push_back(it.first);
        }

        vector<int>ans;
        int i=n;
        
        while(i>=0 && ans.size() < k){
            for(int x : bucket[i]){
                ans.push_back(x);
                
                if(ans.size()==k){
                break;
            }
            }
            i--;
        }
        return ans;
    }
};