class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            int a = nums[i];
            int b = nums[i-1];
           if ( !(a & 1) ^ (b & 1) ){
                return false;
           }
        }
        return true;
    }
};