class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for(int i=0;i<=n-m;i++){
            int j =0;
            int idx = i;
            
            while(j<m){
                if(haystack[idx] == needle[j]){
                    idx++;
                    j++;
                }else{
                    break;
                }
            }
            if(j==m){
                return i;
            }
        }
        return -1;
    }
};