class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n;i++){
            int a = nums[i];
            int b = nums[i-1];
           if ( a%2 == b%2 ){
                return false;
           }
        }
        return true;
    }
};