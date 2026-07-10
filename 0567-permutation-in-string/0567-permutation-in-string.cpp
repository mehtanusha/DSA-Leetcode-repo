class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();
        
        if(n2 < n1) return false;

        vector<int>freqs1(26,0);
        vector<int>freqwind(26,0);
        for(int i=0;i<n1;i++){
            freqs1[s1[i] - 'a']++;
        }

        int i=0;
        int j=0;
        while(j<n2){
          freqwind[s2[j]-'a']++;
          
          while(j-i+1 > n1){
            freqwind[s2[i]-'a']--;
            i++;
          }
          if(j-i+1 == n1){
            if(freqs1 == freqwind){
                return true;
          }
          }
          j++;
        } 
        return false;
    }
};