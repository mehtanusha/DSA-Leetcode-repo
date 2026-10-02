class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();

        string ans(n,' ');
        priority_queue<pair<int,char>>pq;

        vector<int>freq(26,0);
        for(int i : s){
            freq[i-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i] > 0){
                pq.push({freq[i],i+'a'});
            }
        }
        int idx = 0;
        while(!pq.empty()){
            int freq = pq.top().first;
            char ch = pq.top().second;
            pq.pop();
            while(freq > 0){
                if(idx >= n){
                    idx = 1;
                }
                ans[idx] = ch;
                idx+=2;
                freq--;
            }
        }
        for(int i=1;i<n;i++){
            if(ans[i] == ans[i-1]){
                return "";
            }
        }
        return ans;
    }
};