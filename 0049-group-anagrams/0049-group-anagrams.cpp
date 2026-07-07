class Solution {
public:
    string generate(string &word){
        int freq[26] = {0};
        string newword = "";
        for(char ch : word){
            freq[ch-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i] > 0){
                newword += string(freq[i], i +'a');
            }
        }
        return newword;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>>ans; 
        unordered_map<string,vector<string>>mp;
        int freq[26] = {0};

        for(int i=0;i<n;i++){
            string word = strs[i];
            string newword = generate(word);

            mp[newword].push_back(word);
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};