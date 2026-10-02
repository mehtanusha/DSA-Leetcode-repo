class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        priority_queue<pair<int,char>>pq;
        vector<int>freq(26,0);

        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i] > 0){
                pq.push({freq[i],i+'a'});
            }
        }

        string ans(n,' ');
        int idx = 0;
        while(!pq.empty()){
            char ch = pq.top().second;
            int freq = pq.top().first;
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