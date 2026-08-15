class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int>st(nums1.begin(),nums1.end());
        unordered_set<int>res;

        for(int num : nums2){
            if(st.count(num)){
                res.insert(num);
            }
        }
        vector<int>ans;
        for(auto &it : res){
            ans.push_back(it);
        }
        return ans;
    }
};