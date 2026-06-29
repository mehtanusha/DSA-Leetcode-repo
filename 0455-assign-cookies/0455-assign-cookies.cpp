class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        int i = 0; //pointer for g
        int j = 0; //pointer for s
        int ans = 0;

        while(i<g.size() && j<s.size()){
            if(s[j] >= g[i]){
                ans++;
                i++;
                j++;
            }else{
                j++;
            }
        } return ans;
    }
};