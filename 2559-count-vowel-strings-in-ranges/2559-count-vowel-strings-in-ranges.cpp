class Solution {
public:

    bool isvowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' ||c == 'u'){
            return true;
        }
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();

        vector<int>prefix(n,0);

        //prefix sum
        for(int i=0;i<n;i++){
            if(isvowel(words[i].front()) && isvowel(words[i].back())){
                prefix[i] = 1;
            }
            
            if(i>0){
                prefix[i] += prefix[i-1];
            }
        }
        
        vector<int>ans;
        for(auto &q : queries){
            int l = q[0];
            int r = q[1];

            if(l == 0){
                ans.push_back(prefix[r]);
            }
            else{
                ans.push_back(prefix[r] - prefix[l-1]);
            }
        }
        return ans;
    }
};