class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int>freq;
        int n = nums.size();

        for(int num : nums){
            freq[num]++;
        }
        int dominant = 0;
        int totalfreq = 0;
        for(auto &it : freq){
            if(it.second > n/2){
                dominant = it.first;
                totalfreq = it.second;
                break;
            }
        }
        int leftfreq = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == dominant){
                leftfreq++;
            }
            int leftlength = i+1;
            int rightlength = n-1-i;
            int rightfreq = totalfreq - leftfreq;

            if(leftfreq > leftlength/2 && rightfreq > rightlength/2){
                return i;
            }
        }
        return -1;
    }
};