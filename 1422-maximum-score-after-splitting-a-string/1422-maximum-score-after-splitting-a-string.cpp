class Solution {
public:
    int maxScore(string s) {
        int maxi = INT_MIN;
        int count = 0;
        int n = s.size();

        vector<int>ones(n,0);
        if(s[n-1] == '1'){
            ones[n-1] = 1;
        }
        for(int i=n-2;i>=0;i--){
            ones[i] = ones[i+1];
            if(s[i] == '1'){
                ones[i]++;
            }
        }

        for(int i=0;i<n-1;i++){
            if(s[i] == '0'){
                count ++;
            }
            maxi =  max(maxi, ones[i+1] + count);
        }
        return maxi;
    }
};