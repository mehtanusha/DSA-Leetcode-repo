class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {

        int ones = 0;
        vector<int> zeroGroups;

        int cnt = 0;

        for(char ch : s){

            if(ch == '1'){
                ones++;

                if(cnt > 0){
                    zeroGroups.push_back(cnt);
                    cnt = 0;
                }
            }
            else{
                cnt++;
            }
        }

        if(cnt > 0)
            zeroGroups.push_back(cnt);


        int gain = 0;

        // minimum 2 zero groups required
        if(zeroGroups.size() >= 2){

            for(int i = 0; i < zeroGroups.size()-1; i++){

                gain = max(gain,
                           zeroGroups[i] + zeroGroups[i+1]);
            }
        }

        return ones + gain;
    }
};