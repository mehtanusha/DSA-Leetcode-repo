class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int,int>>st;

        for(char ch : s){
            if(!st.empty() && st.back().first == ch){
                st.back().second++;
            }
            else{
                st.push_back({ch,1});
            }
            if(st.back().second == k){
                st.pop_back();
            }
        }
        string ans = "";

        for(auto x : st){
            ans += string(x.second,x.first);
        }
        return ans;
    }
};