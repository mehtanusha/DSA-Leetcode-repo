class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int count = 0;

        //left to right

        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                count ++;
            }
            else if(s[i] == ')'){
                if(count > 0){
                    count --;
                }
                else{
                    s[i] = '#';
                }
            }
        }

        count = 0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == ')'){
                count ++;
            }
            else if(s[i] == '('){
                if(count > 0){
                    count --;
                }
                else{
                    s[i] = '#';
                }
            }
        }
        string ans = "";
        for(char ch : s){
            if(ch != '#'){
                ans += ch;
            }
        }
        return ans;

    }
};