class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>st;

        for(char ch : allowed){
            st.insert(ch);
        }

        int ans = 0;
        for(string s : words){
            int count = 0;

            for(char ch : s){
                if(st.find(ch) != st.end()){
                    count++;
                }
                else{
                    break;
                }
            }
            if(count == s.size()){
                ans++;
            }
        }
        return ans;
    }
};