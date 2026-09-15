class Solution {
public:
    string largestGoodInteger(string num) {
       char ans = ' ';

       for(int i=0;i<num.size() -2;i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                if(num[i] > ans){
                    ans = num[i];
                }
            }
       }
       if(ans == ' ') return "";
       return string(3,ans);
    }
};