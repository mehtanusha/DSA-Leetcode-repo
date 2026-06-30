class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int opencount = 0;
        int closecount = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '(' || s[i] == '*'){
                opencount++;
            }
            else{
                opencount--;
            }
            if(opencount < 0){
                return false;
            } 
        }
        for(int j=n-1;j>=0;j--){
            if(s[j] == ')' || s[j] == '*'){
                closecount++;
            }
            else{
                closecount--;
            }
            if(closecount < 0){
                return false;
            } 
        }
        return true;
    }
};