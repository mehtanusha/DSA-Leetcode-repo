class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>deq;
        vector<int>ans;
        int n = nums.size();

        for(int i=0;i<n;i++){
            while(!deq.empty() && deq.front() <= i-k){
                deq.pop_front();
            }
            
            while(!deq.empty() && nums[i] > nums[deq.back()]){
                deq.pop_back();
            }
            deq.push_back(i);
            if(i>=k-1){
                ans.push_back(nums[deq.front()]);
            }
        } 
        return ans;
    }
};