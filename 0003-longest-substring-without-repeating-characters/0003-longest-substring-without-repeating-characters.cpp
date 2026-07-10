class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int maxlen = 0;

        vector<int>freq(256,-1);
        
        int i =0;
        for(int j=0;j<n;j++){
            freq[s[j]] ++;
            while(freq[s[j]] > 0){
                freq[s[i]]--;
                i++;
            }

            maxlen = max(maxlen,j-i+1);
        }
        return maxlen;
    }
};