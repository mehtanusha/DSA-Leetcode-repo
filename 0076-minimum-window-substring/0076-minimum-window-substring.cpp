class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;

        if(t.size() > s.size()){
            return "";
        }

        for(char &ch : t){
            mp[ch]++;
        }

        int i=0;
        int j=0;
        int minwindowsize = INT_MAX;
        int start_i = 0;
        int countrequired = t.size();

        while(j<s.size()){
            if(mp[s[j]] > 0){
                countrequired--;
            }
            mp[s[j]]--;

            while(countrequired == 0){
                if(j-i+1 < minwindowsize){
                    minwindowsize = j-i+1;
                    start_i = i;
                }
                mp[s[i]] ++;

                if(mp[s[i]] > 0){
                    countrequired++;
                }
                i++;
            }
            j++;
        }
        if(minwindowsize == INT_MAX){
            return "";
        }
        return s.substr(start_i,minwindowsize);

    }
};