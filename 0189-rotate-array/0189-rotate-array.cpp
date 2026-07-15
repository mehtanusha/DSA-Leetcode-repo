class Solution {
public:
    // void reverse(int i,int j,vector<int>& nums){
        
    // }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();

        if(n == k){
            return;
        }

        int newk = k%n;

        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin() + newk);
        reverse(nums.begin()+newk,nums.end());
        return ;
    }
};