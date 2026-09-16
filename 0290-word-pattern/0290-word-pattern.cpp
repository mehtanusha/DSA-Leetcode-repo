class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>words;
        stringstream ss(s);
        string word;
        while(ss >> word){
            words.push_back(word);
        }

        int n = pattern.size();
        int m = words.size();

        if(n != m) return false;

        unordered_map<char,string>mp;
        set<string>used;

        for(int i=0;i<n;i++){
            char ch = pattern[i];
            string word= words[i];

            if(mp.count(ch)){
                if(mp[ch] != word){
                    return false;
            }
            }
            else{
                if(used.count(word)){
                    return false;
                }
                mp[ch] = word;
                used.insert(word);
            }
        }
        return true;
    }
};