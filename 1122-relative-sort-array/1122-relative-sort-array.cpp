class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>freq;

        for(int num : arr1){
            freq[num]++;
        }

        vector<int>ans;
        int n = arr2.size();
        for(int i=0;i<n;i++){
            while(freq[arr2[i]] > 0){
                ans.push_back(arr2[i]);
                freq[arr2[i]]--;
            }
        }
       vector<int>rem;
       for(auto &it : freq){
        while(it.second >0){
            rem.push_back(it.first);
            it.second--;
        }
       }
       sort(rem.begin(),rem.end());

       for(int num : rem){
        ans.push_back(num);
       }
        return ans;
    }
};