class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        set<int>st;

        for(int x : arr){
            st.insert(x);
        }

        unordered_map<int,int>mp;

        int rank = 1;
        for(int i : st){
            mp[i] = rank;
            rank++;
        }

        for(int i=0;i<n;i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};