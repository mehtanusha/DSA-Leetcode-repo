class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        vector<int>freq(256,0);

        int i = 0;
        int j = 0;
        int maxfreq = 0;
        int maxlen = 0;

        while(j<n){
            freq[s[j]]++;
            maxfreq = max(maxfreq,freq[s[j]]);

            while((j-i+1)-maxfreq > k){
                freq[s[i]]--;
                i++;
            }
            maxlen = max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};