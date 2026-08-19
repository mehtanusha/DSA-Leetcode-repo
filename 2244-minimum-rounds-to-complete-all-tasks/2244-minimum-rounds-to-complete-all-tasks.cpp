class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int>mp;

        for(int task : tasks){
            mp[task]++;
        }
        int rounds = 0;
        for(auto &it : mp){
            int freq = it.second;

            if(freq == 1){
                return -1;
            }
            else if(freq % 3 == 0){
                rounds += freq/3;
            }
            else if(freq % 3 == 1 || freq % 3 == 2){
                rounds += freq/3 + 1;
            }
        }
        return rounds;
    }
};