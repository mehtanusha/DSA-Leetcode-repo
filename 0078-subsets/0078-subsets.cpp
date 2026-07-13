class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>>ans;

        //total subsets
        for(int num = 0; num <(1<<n);num++){
            vector<int>temp;

            //check every bit
            for(int i=0;i<n;i++){

                //if ith bit is set(1)
                if(num & (1<<i)){
                    temp.push_back(nums[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};