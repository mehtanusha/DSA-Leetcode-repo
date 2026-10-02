class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();
        vector<int>freq(26,0);

        for(char &ch : tasks){
            freq[ch-'A']++;
        }
        sort(freq.begin(),freq.end());

        int maxfreq = freq[25];
        int gaddhe =  maxfreq - 1;
        int idleslots = n * gaddhe;

        for(int i=24;i>=0;i--){
            idleslots -= min(freq[i],gaddhe);
        }
        if(idleslots > 0){
            return tasks.size() + idleslots;
        }
        return tasks.size();
    }
};