class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int>freq(26,0);

        for(int i=0;i<words.size();i++){
            for(char ch : words[i]){
                freq[ch-'a']++;
            }
        }

        for(int i=0;i<26;i++){
            if(freq[i] % words.size() != 0){
                return false;
            }
        }
        return true;
    }
};