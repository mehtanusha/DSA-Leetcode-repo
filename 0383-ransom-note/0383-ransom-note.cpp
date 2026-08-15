class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int>mp;
        unordered_map<char,int>freq;

        for(char c : magazine){
            mp[c]++;
        }
        for(char note : ransomNote){
            freq[note]++;
        }

        for(char ch : ransomNote){
            if(mp[ch] < freq[ch]){
                return false;
            }
        }
        return true;
    }
};