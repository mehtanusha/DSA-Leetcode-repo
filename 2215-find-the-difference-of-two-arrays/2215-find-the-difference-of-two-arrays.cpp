class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int>a,b;

        unordered_set<int>st1(nums1.begin(),nums1.end());
        unordered_set<int>st2(nums2.begin(),nums2.end());

        for(auto x : st1){
            if(st2.find(x) == st2.end()){
                a.push_back(x);
            }
        }
        for(auto x : st2){
            if(st1.find(x) == st1.end()){
                b.push_back(x);
            }
        }
        return {a,b};
    }
};