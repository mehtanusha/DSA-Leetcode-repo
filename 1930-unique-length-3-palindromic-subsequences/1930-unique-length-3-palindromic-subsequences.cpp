class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int ans = 0;

        for(char ch ='a';ch <= 'z';ch++){
            int first = s.find(ch);
            int last = s.rfind(ch);

            if(first != -1 && first < last){
                set<char>st;
                for(int i=first+1;i<last;i++){
                    st.insert(s[i]);
                } 
                ans += st.size();
            }
        }
        return ans;
    }
};