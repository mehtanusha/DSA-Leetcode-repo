class Solution {
public:
    int maxDifference(string s) {
        int freq[26] = {0};

        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        int mineven = INT_MAX;
        int maxodd = INT_MIN;

        for(int i=0;i<26;i++){
            if(freq[i] == 0) continue;
            if(freq[i] %2 == 0){
                mineven = min(mineven,freq[i]);
            }else{
                maxodd = max(maxodd,freq[i]);
            }
        }
        return maxodd-mineven;
    }
};