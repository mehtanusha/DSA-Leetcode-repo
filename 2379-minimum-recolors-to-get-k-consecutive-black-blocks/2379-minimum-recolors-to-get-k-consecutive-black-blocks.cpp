class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i=0;
        int j=0;

        int cnt = 0;
        int size = 0;
        int ans = INT_MAX;
        int n =  blocks.size();
        while(j<n){
            size++;
            if(blocks[j] == 'W'){
                cnt++;
            }
            if(size == k){
                ans = min(ans,cnt);
                if(blocks[i] == 'W'){
                    cnt--;
                }
                i++;
                size--;
            }
            j++;
        }
        return ans;
    }
};