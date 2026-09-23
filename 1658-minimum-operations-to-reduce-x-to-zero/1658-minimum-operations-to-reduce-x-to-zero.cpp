class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int maxlen = -1;
        int i=0;
        int j=0;
        int sum = 0;

        int total = accumulate(nums.begin(),nums.end(),0);
        int req = total - x;
        
        if(x>total){
            return -1;
        }

        while(j<n){
            sum += nums[j];
            while(sum > req){
                sum -= nums[i];
                i++;
            }
            if(sum == req){
                maxlen = max(maxlen,j-i+1);
            }
            j++;
        }
        if(maxlen == -1) return -1;
        return n-maxlen;
    }
};