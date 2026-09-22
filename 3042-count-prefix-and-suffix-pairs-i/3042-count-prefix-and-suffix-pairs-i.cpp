class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans  = 0;
        int n = words.size();

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                string a = words[i];
                string b = words[j];

                if(b.find(a) == 0 && b.rfind(a) == b.size() - a.size()){
                    ans++;
                }
            }
        }
        return ans;
    }
};