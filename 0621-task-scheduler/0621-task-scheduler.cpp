class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);

        for(int t : tasks){
            freq[t-'A']++;
        }
        priority_queue<int>pq;

        for(int i=0;i<26;i++){
            if(freq[i] > 0){
                pq.push(freq[i]);
            }
        }

        int time = 0;

        while(!pq.empty()){
            vector<int>temp;
            for(int i=0;i<n+1;i++){
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int it : temp){
                if(it > 0){
                    pq.push(it);
                }
            }

            if(!pq.empty()){
                time += n + 1;
            }else{
                time += temp.size();
            }
        }
        return time;
    }
};