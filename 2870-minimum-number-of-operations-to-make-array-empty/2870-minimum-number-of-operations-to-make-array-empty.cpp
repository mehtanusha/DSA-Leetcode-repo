class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int>mp;

        for(int num : nums){
            mp[num]++;
        }

        int cnt = 0;
        for(auto &it : mp){
            int num = it.second;
            if(num == 1){
                return -1;
            }
            else if(num % 3 == 0){
                cnt += num/3;
            }
            else if(num % 3 == 1 || num %3 == 2){
                cnt += num/3 + 1;
            }
        }
        return cnt;
    }
};