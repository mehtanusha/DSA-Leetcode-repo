class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        vector<int>arr(26,-1);
        int ans = -1;
        for(int i=0;i<s.size();i++){
            int index = s[i] - 'a';
            if(arr[index]== -1){
                arr[index] = i;
            }
            else{
                ans = max(ans,i-arr[index] - 1);
            }
        }
        return ans;
    }
};