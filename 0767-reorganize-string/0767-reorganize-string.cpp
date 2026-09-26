class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        vector<int> freq(26, 0);

        for(char c : s){
            freq[c - 'a']++;
        }

        string ans(n, ' ');

        int maxfreq = 0;
        char maxchar;

        // Find maximum frequency character
        for(int i = 0; i < 26; i++){
            if(freq[i] > maxfreq){
                maxfreq = freq[i];
                maxchar = 'a' + i;
            }
        }

        // Impossible case
        if(maxfreq > (n + 1) / 2){
            return "";
        }

        int idx = 0;

        // Place maximum frequency character
        while(freq[maxchar - 'a'] > 0){
            ans[idx] = maxchar;
            freq[maxchar - 'a']--;

            idx += 2;

            if(idx >= n){
                idx = 1;
            }
        }

        // Place remaining characters
        for(int i = 0; i < 26; i++){
            while(freq[i] > 0){
                ans[idx] = 'a' + i;
                freq[i]--;

                idx += 2;

                if(idx >= n){
                    idx = 1;
                }
            }
        }

        return ans;
    }
};