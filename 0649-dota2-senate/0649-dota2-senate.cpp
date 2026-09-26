class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int>dire;
        queue<int>radiant;
        int n = senate.size();

        for(int i=0;i<n;i++){
            if(senate[i] == 'R'){
                radiant.push(i);
            }
            else{
                dire.push(i);
            }
        }

        while(!dire.empty() && !radiant.empty()){
            int d_idx = dire.front();
            dire.pop();

            int r_idx = radiant.front();
            radiant.pop();

            if(d_idx < r_idx){
                dire.push(d_idx + n);
            }else{
                radiant.push(r_idx + n);
            }
        }
        if(dire.empty()){
            return "Radiant";
        }
        return "Dire";
    }
};