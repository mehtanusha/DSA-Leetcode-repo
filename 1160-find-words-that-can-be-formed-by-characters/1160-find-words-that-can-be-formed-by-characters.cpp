class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
       int count =0;
       vector<int>freq(26,0);
       for(char ch : chars){
        freq[ch - 'a']++;
       }

        for(string word : words){
            vector<int>cnt(26,0);
            for(char c : word){
                cnt[c-'a']++;
            }
            bool valid = true;
            for(int i=0;i<26;i++){
                if(freq[i] < cnt[i]){
                    valid = false;
                   break;
                }
            }
            if(valid){
                count += word.length();
            }
        }
        return count;
    }
};