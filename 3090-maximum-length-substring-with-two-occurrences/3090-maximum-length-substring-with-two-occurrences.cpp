class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int>freq(216,0);
        int i = 0;
        int j = 0;
        int len = 0;
        int maxlen = 0;
        int n = s.size();

        while(j<n){
            freq[s[j]]++;
            while(freq[s[j]] > 2){
                freq[s[i]]--;
                len--;
                i++;
            }
            len++;
            maxlen = max(len,maxlen);
            j++;

        }
        return maxlen;
    }
};