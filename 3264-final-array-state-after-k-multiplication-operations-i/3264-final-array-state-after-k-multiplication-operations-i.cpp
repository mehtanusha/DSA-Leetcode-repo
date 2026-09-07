class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
          priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        for(int i=0;i<nums.size();i++){
            pq.push({nums[i],i});
        }

        while(k!=0){
            auto [value,index] = pq.top();
            pq.pop();
            value = value * multiplier;
            nums[index] = value;
            pq.push({value,index});
            k--;
        }
        return nums;
    }
};