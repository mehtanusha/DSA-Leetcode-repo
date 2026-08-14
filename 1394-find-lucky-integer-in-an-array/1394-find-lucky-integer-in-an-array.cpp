class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int>freq;

        int n = arr.size();
        int maxi = -1;
        for(int i=0;i<n;i++){
            freq[arr[i]]++;
        }
        for(int i=0;i<n;i++){
            if(freq[arr[i]] == arr[i]){
                maxi = max(maxi,freq[arr[i]]);
            }
        }
        return maxi;
    }
};