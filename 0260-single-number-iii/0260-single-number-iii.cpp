class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        long long xorr = 0;
        for(int i=0;i<n;i++){
            xorr = xorr ^ nums[i];
        }
        long long mask = xorr & (-xorr);

        int group_A = 0;
        int group_B = 0;
        for(int i = 0;i<n;i++){
            int num = mask & nums[i];

            if(num == 0){
                group_B = group_B ^ nums[i];
            }
            else{
                group_A = group_A ^ nums[i];
            }
        }
        return {group_A , group_B};
    }
};