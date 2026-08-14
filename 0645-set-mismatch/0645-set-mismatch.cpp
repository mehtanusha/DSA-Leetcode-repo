class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int first = 0;
        int second = 0;
        for(int i=1;i<n;i++){
            if(nums[i-1] == nums[i]){
                first = nums[i];
                break;
            }
        }
        int total = (n * (n+1) )/2;
        int sum = 0;
        for(int i=0;i<n;i++){
            sum = sum + nums[i];
        }
        second = (total - sum) + first;
        return {first,second};
    }
};